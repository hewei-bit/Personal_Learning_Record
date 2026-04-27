#include "thread_pool.h"

void handler(void *arg)
{
    //响应取消请求之后自动处理例程,释放互斥锁
    pthread_mutex_unlock((pthread_mutex_t *)arg);
}

void *routine(void *arg)
{
    thread_pool *pool = (thread_pool *)arg;
    struct task *p;

    while(1)
    {
        // 访问任务队列前加锁,为防止取消后死锁,注册处理例程 handler
        pthread_cleanup_push(handler, (void *)&pool->lock);
        pthread_mutex_lock(&pool->lock);

        // 若当前没有任务,且线程池未关闭,则进入条件变量等待队列睡眠
        while(pool->waiting_tasks == 0 && !pool->shutdown)
        {
            pthread_cond_wait(&pool->cond, &pool->lock);
        }

        // 若当前没有任务,且线程池关闭标识为真,则立即释放互斥锁并退出
        if(pool->waiting_tasks == 0 && pool->shutdown == true)
        {
            pthread_mutex_unlock(&pool->lock);
            pthread_exit(NULL);
        }

        // 若当前有任务,则消费任务队列中的任务
        p = pool->task_list->next;
        pool->task_list->next = p->next;
        pool->waiting_tasks--;

        // 释放互斥锁,并弹栈 handler(但不执行他)
        pthread_mutex_unlock(&pool->lock);
        pthread_cleanup_pop(0);

        // 执行任务,并且在此期间禁止响应取消请求
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
        (p->task)(p->arg);
        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

        free(p);
    }
    pthread_exit(NULL);
}

bool init_pool(thread_pool *pool, unsigned int threads_number)
{
    pthread_mutex_init(&pool->lock, NULL);
    pthread_cond_init(&pool->cond, NULL);

    pool->shutdown = false; // 关闭销毁线程池标识
    pool->task_list = malloc(sizeof(struct task)); // 任务队列头结点
    pool->tids = malloc(sizeof(pthread_t) * MAX_ACTIVE_THREADS);
    {
        if(pool->task_list == NULL || pool->tids == NULL)
        {
            perror("allocate memory error");
            return false;
        }
        pool->task_list->next = NULL;
        pool->waiting_tasks = 0;
        pool->active_threads = threads_number;
        int i;
        for(i=0; i<pool->active_threads; i++) // 创建指定数目线程
        if(pthread_create(&((pool->tids)[i]), NULL,routine, (void *)pool) != 0)
        {
            perror("create threads error");
            return false;
        }
    }
    return true;        
}

bool add_task(thread_pool *pool,void *(*task)(void *arg), void *arg)
{
    struct task *new_task = malloc(sizeof(struct task)); // 新任务节点
    if(new_task == NULL)
    {
        perror("allocate memory error");
        return false;
    }
    new_task->task = task;
    new_task->arg = arg;
    new_task->next = NULL;
    // 访问任务队列前获取互斥锁,此处无需注册取消处理例程
    pthread_mutex_lock(&pool->lock);
    if(pool->waiting_tasks >= MAX_WAITING_TASKS)
    {
        pthread_mutex_unlock(&pool->lock);
        fprintf(stderr, "too many tasks.\n");
        free(new_task);
        return false;
    }
    struct task *tmp = pool->task_list;
    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new_task; // 添加新的任务节点
    pool->waiting_tasks++;
    // 释放互斥锁,并唤醒其中一个阻塞在条件变量上的线程
    pthread_mutex_unlock(&pool->lock);
    pthread_cond_signal(&pool->cond);

    return true;
}

int add_thread(thread_pool *pool, unsigned additional_threads)
{
    if(additional_threads == 0)
        return 0;
    
    unsigned total_threads = pool->active_threads + additional_threads;
    int i, actual_increment = 0;

    // 循环地创建若干指定数目的线程
    for(i = pool->active_threads;i < total_threads && i < MAX_ACTIVE_THREADS;i++)
    {
        if(pthread_create(&((pool->tids)[i]),NULL, routine, (void *)pool) != 0)
        {
            perror("add threads error");
            if(actual_increment == 0)
                return -1;
            break;
        }
        actual_increment++;
    }
        pool->active_threads += actual_increment;
        return actual_increment;
 }


int remove_thread(thread_pool *pool, unsigned int removing_threads)
{
    if(removing_threads == 0)
        return pool->active_threads;
    int remain_threads = pool->active_threads - removing_threads; remain_threads = remain_threads > 0 ? remain_threads : 1;
    int i; // 循环地取消掉指定数目的线程
    for(i=pool->active_threads-1; i>remain_threads-1; i--)
    {
        errno = pthread_cancel(pool->tids[i]);
        if(errno != 0)
        break;
    }
    if(i == pool->active_threads-1)
        return -1;
    else
    {
        pool->active_threads = i+1;
        return i+1;
    }
}

bool destroy_pool(thread_pool *pool)
{
    pool->shutdown = true;
    pthread_cond_broadcast(&pool->cond);
    int i;
    for(i=0; i<pool->active_threads; i++)
    {
        errno = pthread_join(pool->tids[i], NULL);
        if(errno != 0)
        {
            printf("join tids[%d] error: %s\n",
            i, strerror(errno));
        }
        else
            printf("[%u] is joined\n", (unsigned)pool->tids[i]);
    }
    free(pool->task_list);
    free(pool->tids);
    free(pool);
    return true;
}