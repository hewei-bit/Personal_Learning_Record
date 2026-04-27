#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>


/* 声明管理结构体 */
struct queue
{
	int size;
	int *queue;
	int front;  //队头偏移量
	int rear;   //队尾偏移量
};

/* 顺序队列初始化 */
struct queue *init_queue(int size)
{
	struct queue *p = malloc(sizeof(struct queue));
	if(p == NULL)
	{
		printf("malloc err!\n");
		return NULL;
	}
	
	p->size = size;
	p->queue = malloc(size*sizeof(int));
	if(p->queue == NULL)
	{
		printf("malloc err!\n");
		return NULL;
	}
	p->front = 0;
	p->rear = 0;
	return p;
}

/* 判断队列是否为满 */
bool queue_full(struct queue *p)
{
	return p->front == (p->rear+1)%p->size;
}

/* 数据入队 */
int in_queue(struct queue *p, int data)
{
	if(queue_full(p))
		return -1;
	
	p->rear = (p->rear+1)%p->size;
	p->queue[p->rear] = data;
	return 0;
}

/* 判断队列是否为空 */
bool queue_empty(struct queue *p)
{
	return p->front == p->rear;
}

/* 数据出队 */
int out_queue(struct queue *p, int *data)
{
	if(queue_empty(p))
		return -1;
	
	p->front = (p->front+1)%p->size;
	*data = p->queue[p->front];
	return 0;
}

int arr[10] = {1,2,3,4,5,6,7,8,9,0};

void *fun(void *arg)
{
    sleep(5);
    struct queue *queue = (struct queue *)arg;
    int num = 2;
    while(num > 0)
    {
        int i = 0;
        for(i = 0;i < 10;i++)
        {
            int data;
            if(!out_queue(queue, &data))
					printf("out queue:%d\n", data);
				else
					printf("queue is empty\n");
            sleep(1);
        }
        sleep(1);
        num--;
    }
    pthread_exit(NULL);
};

int main()
{
    
    struct queue *queue = init_queue(10);
    //创建线程
    pthread_t tid;
    pthread_create(&tid,NULL,fun,(void *)queue);
    //
    int num = 2;
    while(num > 0)
    {
        int i = 0;
        for(i = 0;i < 10;i++)
        {
            in_queue(queue,arr[i]);
            printf("in queue:%d \n",arr[i]);
            sleep(1);
        }
        sleep(1);
        num--;
    }
    pthread_exit(NULL);
    return 0;
}

