#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

int money = 0;
pthread_mutex_t m;
pthread_cond_t v;

/* 线程的执行例程 */
void *fun(void *arg)
{
	printf("i: %d\n",(int)arg);

	pthread_mutex_lock(&m);
	while(money < 100)
	{
		printf("%d is wait \n",(int)arg);
		pthread_cond_wait(&v,&m);
	}

	sleep(1);
	money -= 100;
	printf("%d take 100 \n",(int)arg);
	pthread_mutex_unlock(&m);

	pthread_exit(NULL);
}

int main(void)
{
	pthread_mutex_init(&m,NULL);
	pthread_cond_init(&v,NULL);

	
	/* 创建线程 1*/
	// char arr[3] = {"abc"};
	int i = 5;
	pthread_t tid;
	while(i--)
		pthread_create(&tid, NULL, fun, (void *)i);


	
	//主线程
	sleep(2);
	//枷锁
	pthread_mutex_lock(&m);

	money +=600;
	printf("money : %d \n",money);
	//解锁
	pthread_mutex_unlock(&m);

	// while(i!=5)
	// {
	// 	pthread_cond_signal(&v);
	// 	i++;
	// 	sleep(2);
	// }
	//广播条件变量
	pthread_cond_broadcast(&v);

	pthread_exit(NULL);

	pthread_mutex_destroy(&m);
	pthread_cond_destroy(&v);
	return 0;
}