#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>
#include <signal.h>

#define FIFO "/home/hewei/chat"
#define SIZE 100

int fd;
//读取jack的消息
void read_msg(int sig)
{
	if(sig == SIGRTMAX)
	{
		char msg_r[SIZE];
		bzero(msg_r,SIZE);
		read(fd, msg_r, sizeof(msg_r));
		printf("from jack:%s\n", msg_r);
	}
}

//获取进程名进程号
int pid()
{
	FILE *fp = popen("ps -e | grep \'jack\' | awk \'{print $1}\'", "r");//打开管道，执行shell 命令
    char buffer[10] = {0};
    int pid;
    while (NULL != fgets(buffer, 10, fp)) //逐行读取执行结果并打印
    {
       // printf("PID:  %s", buffer);
        pid = atoi(buffer);
        //printf("pid:%d\n", pid);
    }
    
    pclose(fp); //关闭返回的文件指针，与popen配套使用,注意不是用fclose噢
	return pid;
}


int main(int argc, char **argv[])
{
	printf("%d\n", getpid());
	if(access(FIFO, F_OK))
	{
		int ret = mkfifo(FIFO, 0666);
		if(-1 == ret)
		{
			perror("mkfifo() failed:");
			exit(1);
		}
	}
	
	fd = open(FIFO, O_RDWR);
	if(-1 == fd)
	{
		perror("open() failed:");
		exit(1);
	}
	
	char msg_w[SIZE];
	signal(SIGRTMAX,read_msg);

	int pid ;
    printf("pid : ");
    scanf("%d",&pid);
    getchar();

	while(1)
	{
		bzero(msg_w, SIZE);
		printf("rose:");
		fgets(msg_w, SIZE, stdin);
		write(fd, msg_w, strlen(msg_w));
		
		kill(pid,SIGRTMIN);		
	}
		
	close(fd);
	
	unlink(FIFO);

	return 0;
}