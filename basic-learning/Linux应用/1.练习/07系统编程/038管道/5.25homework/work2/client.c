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
#include <time.h>

#define FIFO "/home/hewei/ser"
#define LOGBOOK "/home/hewei/logbook.txt"

#define SIZE 100


int main(int argc, char **argv[])
{
	//1.判断管道是否被创建
	if(access(FIFO,F_OK))
	{
		int ret = mkfifo(FIFO, 0666);
		if(-1 == ret)
		{
			perror("mkfifo() failed:");
			exit(1);
		}
	}
	
	//2.打开文件
	int fd_fifo = open(FIFO, O_RDWR);
	if(-1 == fd_fifo)
	{
		perror("open() failed:");
		exit(1);
	}
	
	//3.写
	time_t t;
	char msg_w[SIZE];
	
	while(1)
	{
		time(&t);
		bzero(msg_w,SIZE);
		sprintf(msg_w,"%d%s", getpid(), ctime(&t));
		
		printf("%s", msg_w);
		write(fd_fifo, msg_w, sizeof(msg_w));
		
		sleep(1);
	}
	
	//4.关闭文件
	close(fd_fifo);
	
	return 0;
}