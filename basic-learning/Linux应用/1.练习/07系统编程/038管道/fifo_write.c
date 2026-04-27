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



#define FIFONAME "/home/hewei/tmpfifo"

int main(int argc, char **argv)
{
	if(access(FIFONAME, F_OK))
	{
		/* 创建有名管道文件 */
		int ret = mkfifo(FIFONAME, 0777);
		if(ret == -1)
		{
			perror("mkfifo");
			return -1;
		}
	}
	
	/* 打开有名管道文件 */
	int fifo_fd = open(FIFONAME, O_RDWR);
	if(fifo_fd < 0)
	{
		perror("open");
		return -1;
	}	
	
	while(1)
	{
		/* 向管道文件中写入数据 */
		int ret = write(fifo_fd, "argv[1]", 5);
		if(ret == -1)
		{
			perror("write");
			return -1;
		}
		printf("ret:%d\n", ret);
		usleep(50);
	}

	
	//sleep(10);
	close(fifo_fd);

	
	return 0;
}