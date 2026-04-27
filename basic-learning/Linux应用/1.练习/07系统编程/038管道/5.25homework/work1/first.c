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


#define FIFO_1 "/home/hewei/tmpfifo1"
#define FIFO_2 "/home/hewei/tmpfifo2"
#define SIZE 100

int main(void)
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

	if(access(FIFO_2, F_OK))
	{
		/* 创建有名管道文件2 */
		int ret = mkfifo(FIFO_2, 0777);
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
	/* 打开有名管道文件 2*/
	int fifo_fd_2 = open(FIFO_2, O_RDWR);
	if(fifo_fd_2 < 0)
	{
		perror("open");
		return -1;
	}	
	
	/* 从管道文件1中读出数据 */
	char msg_r[SIZE] = {0};
	char msg_w[SIZE] = {0};

	while(1)
	{
		//对话开始
		bzero(msg_w,SIZE);
		printf("fw_write:");
		fgets(msg_w,SIZE,stdin);//读取
		write(fifo_fd_1, msg_w, strlen(msg_w));
		if(strncmp(msg_w,"exit",4) == 0)
		{
			break;
		}
		//printf("fw_write:%s\n", msg_w);

		bzero(msg_r,SIZE);
		read(fifo_fd_2, msg_r, sizeof(msg_r));
		if(strncmp(msg_r,"exit",4) == 0)
		{
			break;
		}
		printf("fw_read:%s\n", msg_r);
		

	}

	//sleep(10);
	close(fifo_fd_1);
	close(fifo_fd_2);

	
	return 0;
}