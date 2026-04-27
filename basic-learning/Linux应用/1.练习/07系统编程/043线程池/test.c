#include "thread_pool.h"

void *mytask(void *arg)
{
    int n = (int)arg;
    printf("[%u][%s] ==> job will be done in %d sec...\n",(unsigned)pthread_self(), __FUNCTION__, n);
    sleep(n);
    printf("[%u][%s] ==> job done!\n",(unsigned)pthread_self(), __FUNCTION__);
    return NULL;
}


void *count_time(void *arg)
{
    int i =  0;
    while(1)
    {
        sleep(1);
        printf("sec: %d\n", ++i);
    }
}


int main(void)
{

    pthread_t a;
    pthread_create(&a, NULL, count_time, NULL);

    // 1, 初始化一个带有 2 条线程的线程池
    thread_pool *pool = malloc(sizeof(thread_pool));
    init_pool(pool, 2);
    
    // 2, 投入 3 个任务
    printf("throwing 3 tasks...\n");
    add_task(pool, mytask, (void *)(rand()%10));
    add_task(pool, mytask, (void *)(rand()%10));
    add_task(pool, mytask, (void *)(rand()%10));

    // 3, 显示当前有多少条线程
    printf("current thread number: %d\n",
    remove_thread(pool, 0));
    sleep(9);

    // 4, 再投入 2 个任务
    printf("throwing another 2 tasks...\n");
    add_task(pool, mytask, (void *)(rand()%10));
    add_task(pool, mytask, (void *)(rand()%10));

    // 5, 增加 2 条线程
    add_thread(pool, 2);
    sleep(5);

    // 6, 删除 3 条线程
    printf("remove 3 threads from the pool, ""current thread number: %d\n",remove_thread(pool, 3));

    // 7, 销毁线程池
    destroy_pool(pool);
    return 0;
 } 

