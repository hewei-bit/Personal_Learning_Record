#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem;

/* 线程的执行例程 */
void *fun(void *arg)
{
	/* 关闭取消请求 */
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	
	char *buf = (char *)arg;
	// printf("arg:%d, buf:%p\n", (int)arg, buf);
	// pthread_exit(NULL);

	while(1)
	{	
		sem_wait(&sem);
		for(int i = 0; i<3; i++)
		{
			// usleep(1000);
			fprintf(stderr, "%c", buf[i]);
		}
		
		sem_post(&sem);	
		sleep(1);	
	}
}


int main(void)
{
	//初始化无名信号量
	sem_init(&sem, 0, 1);
	
	/* 创建线程 */
	char arr[3] = {"abc"};
	pthread_t tid;
	pthread_create(&tid, NULL, fun, (void *)arr);
	

	char buf[3] = {"123"};
	while(1)
	{	
		sem_wait(&sem);
		for(int i = 0; i<3; i++)
		{
			
			fprintf(stderr, "%c", buf[i]);
		}
		
		sem_post(&sem);
		sleep(1);
	}
	
	
	
	pthread_exit(NULL);
	
	return 0;
}