#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

pthread_mutex_t m;

/* 线程的执行例程 */
void *fun(void *arg)
{
	/* 关闭取消请求 */
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	
	char *buf = (char *)arg;


	while(1)
	{	
		pthread_mutex_lock(&m);
		for(int i = 0; i<3; i++)
		{
			
			fprintf(stderr, "%c", buf[i]);
		}
		pthread_mutex_unlock(&m);
		usleep(1000);	
	}
}


int main(void)
{
	
	pthread_mutex_init(&m, NULL);
	
	
	/* 创建线程 */
	char arr[3] = {"abc"};
	pthread_t tid;
	pthread_create(&tid, NULL, fun, (void *)arr);
	

	char buf[3] = {"123"};
	while(1)
	{	
		pthread_mutex_lock(&m);
		for(int i = 0; i<3; i++)
		{
			
			
			fprintf(stderr, "%c", buf[i]);

		}
		pthread_mutex_unlock(&m);
		usleep(1000);
	}
	
	
	pthread_exit(NULL);
	
	return 0;
}