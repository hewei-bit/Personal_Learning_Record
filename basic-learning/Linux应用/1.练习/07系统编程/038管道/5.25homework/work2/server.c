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
	int fd_log = open(LOGBOOK, O_RDWR|O_CREAT, 0777);
	if(-1 == fd_log)
	{
		perror("open() failed:");
		exit(1);
	}
	
	//3.读写
	char msg_r[SIZE];
	
	while(1)
	{
		bzero(msg_r,SIZE);
		read(fd_fifo, msg_r, sizeof(msg_r));
		printf("%s", msg_r);

		write(fd_log, msg_r, sizeof(msg_r));
		
	}
	
	//4.关闭文件
	close(fd_fifo);
	close(fd_log);
	
	return 0;
}