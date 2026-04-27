#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define FIFO_1 "/home/hewei/tmpfifo1"
#define SIZE 100

void fun(int sig)
{
    printf("pid: %d.sig:%d \n",getpid(),sig);
}

int main(int argc,char **argv)
{
	//创建管道文件
	if(access(FIFO_1, F_OK))
	{
		/* 创建有名管道文件 1*/
		int ret = mkfifo(FIFO_1, 0777);
		if(ret == -1)
		{
			perror("mkfifo");
			return -1;
		}
	}

	/* 打开有名管道文件 1*/
	int fifo_fd_1 = open(FIFO_1, O_RDWR);
	if(fifo_fd_1 < 0)
	{
		perror("open");
		return -1;
	}	
	
	/* 从管道文件1中读出数据 */
	char msg_r[SIZE] = {0};
	char msg_w[SIZE] = {0};

	bzero(msg_w,SIZE);
	printf("first pid:%d \n",getpid());
	sprintf(msg_w,"%d",getpid());
	write(fifo_fd_1, msg_w, strlen(msg_w));
	printf("first send pid to second \n");
	sleep(5);

	bzero(msg_r,SIZE);
	read(fifo_fd_1, msg_r, sizeof(msg_r));
	int second_pid = atoi(msg_r);
	printf("second pid : %d \n",second_pid);
	printf("first receive pid from second \n");
	sleep(5);

	while(1)
	{
		//对话开始
		bzero(msg_w,SIZE);
		printf("first_write:");
		fgets(msg_w,SIZE,stdin);//读取
		write(fifo_fd_1, msg_w, strlen(msg_w));
		if(strncmp(msg_w,"exit",4) == 0)
		{
			break;
		}
		//printf("fw_write:%s\n", msg_w);

		signal(SIGINT,fun);
		sleep(3);
		//pause();

		//读
		bzero(msg_r,SIZE);
		read(fifo_fd_1, msg_r, sizeof(msg_r));
		if(strncmp(msg_r,"exit",4) == 0)
		{
			break;
		}
		printf("first_read:%s\n", msg_r);
		
		kill(second_pid,SIGINT);
	}

	//sleep(10);
	close(fifo_fd_1);

	unlink(FIFO_1);
	
	return 0;
}