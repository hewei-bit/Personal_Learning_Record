#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int num = 0;

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
	//char buf[3] = {"abc"};
	char *buf = (char *)arg;
	// printf("arg:%d, buf:%p\n", (int)arg, buf);
	// pthread_exit(NULL);
	int i = 10;
	char *p =  "1";
	printf("p:%p\n", p);
	
	while(1)
	{
		/* 压栈取消处理例程，让线程在收到取消之后还要执行fun1函数 */
		pthread_cleanup_push(fun1, NULL);
		pthread_cleanup_push(fun2, NULL);
		sleep(1);
		num++;
		/* P操作 */
		for(int i = 0; i<3; i++)
		{
			fprintf(stderr, "%c", buf[i]);
		}
		/* V操作 */
		
		
		pthread_cleanup_pop(0);
		pthread_cleanup_pop(0);
		if(num == 5)
        {
            printf("\n");
            pthread_exit((void *)p);
        }
			
	}
}


int main(void)
{
	char arr[3] = {"abc"};
	/* 创建线程 */
	pthread_t tid;
	pthread_create(&tid, NULL, fun, (void *)arr);
	
	/* 接合子线程 */
	void *retval = NULL;
    pthread_join(tid,&retval);
	// int ret = pthread_tryjoin_np(tid, &retval);
	// if(ret != 0)
	// {
		// printf("%s\n", strerror(ret));
		// return -1;
	// }
	// printf("retval:%d\n", (int)retval);

	printf("*retval:%c\n", *(char *)retval);
	
	char buf[3] = {"123"};
	while(1)
	{
		sleep(1);
		num++;
		for(int i = 0; i<3; i++)
		{
			fprintf(stderr, "%c", buf[i]);	
		}
		if(num == 10)
			pthread_exit(NULL);
		if(num >= 5)
		{
			int ret = pthread_cancel(tid);
			if(ret != 0)
			{
				printf("%s\n", strerror(ret));
			}
		}
			
	}
	
	return 0;
}