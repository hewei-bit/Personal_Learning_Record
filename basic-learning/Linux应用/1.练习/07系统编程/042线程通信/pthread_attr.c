#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>



/* 弹栈处理例程，写被取消之后没有做但是必须做的事情 */
void fun1(void *arg)
{
	/* V操作 */
	printf("fun:%d\n", __LINE__);
}

void fun2(void *arg)
{
	/* V操作 */
	printf("fun:%d\n", __LINE__);
}

/* 线程的执行例程 */
void *fun(void *arg)
{
	/* 关闭取消请求 */
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	
	char *buf = (char *)arg;
	// printf("arg:%d, buf:%p\n", (int)arg, buf);
	// pthread_exit(NULL);
	int j = 0;
	while(1)
	{	
		for(int i = 0; i<3; i++)
		{
			sleep(1);
			fprintf(stderr, "%c", buf[i]);
		}
		j++;
		if(j == 5)
			pthread_exit(NULL);
	}
}


int main(void)
{
	/* 设置分离属性 */
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); //设置分离属性
	
	/*
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED); //设置使用属性变量中的调度策略
	pthread_attr_setschedpolicy(&attr, SCHED_FIFO);				//设置调度策略为FIFO
	struct sched_param arg = {10};
	pthread_attr_setschedparam(&attr, &arg); 					//设置静态优先级为10
	*/
	/* 创建线程 */
	char arr[3] = {"abc"};
	pthread_t tid;
	pthread_create(&tid, &attr, fun, (void *)arr);
	
	/*
	pthread_attr_setschedpolicy(&attr, SCHED_FIFO);	
	arg.sched_priority = 10;
	pthread_attr_setschedparam(&attr, &arg); 
	pthread_t tid1;
	pthread_create(&tid1, &attr, fun, "123");
	*/
	
	pthread_attr_destroy(&attr);
	/* 接合子线程 
	void *retval = NULL;
	int ret = pthread_join(tid, &retval);
	if(ret != 0)
	{
		printf(" %d,%s\n", __LINE__, strerror(ret));
		sleep(10); 	
		return -1;
	}
	printf("retval:%d\n", (int)retval);
	*/
	
	
	sleep(3);
	pthread_cancel(tid);
	
	pthread_exit(NULL);
	
	return 0;
}