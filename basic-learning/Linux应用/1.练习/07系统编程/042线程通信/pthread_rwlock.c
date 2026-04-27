#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

static pthread_rwlock_t rwlock;

int global = 0;

/* 线程的执行例程 */
void *fun1(void *arg)
{
	//对共享资源进行写操作,加写锁
	pthread_rwlock_wrlock(&rwlock);

	global += 1;
	printf("I am %s ,now global = %d \n",(char *)arg, global);

	//解锁
	pthread_rwlock_unlock(&rwlock);

	pthread_exit(NULL);
}

void *fun2(void *arg)
{
	//对共享资源进行写操作,加写锁
	pthread_rwlock_wrlock(&rwlock);

	global = 100;
	printf("I am %s ,now global = %d \n",(char *)arg, global);

	//解锁
	pthread_rwlock_unlock(&rwlock);

	pthread_exit(NULL);
}

void *fun3(void *arg)
{
	//对共享资源进行写操作,加写锁
	pthread_rwlock_rdlock(&rwlock);


	printf("I am %s ,now global = %d \n",(char *)arg, global);

	//解锁
	pthread_rwlock_unlock(&rwlock);

	pthread_exit(NULL);
}

int main(void)
{
	pthread_rwlock_init(&rwlock,NULL);
	
	/* 创建线程 1 2 3*/
	char arr[3] = {"abc"};
	pthread_t t1,t2,t3;
	pthread_create(&t1, NULL, fun1, (void *)arr);
	pthread_create(&t2, NULL, fun2, (void *)arr);
	pthread_create(&t3, NULL, fun3, (void *)arr);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	
	pthread_rwlock_destroy(&rwlock);

	return 0;
}