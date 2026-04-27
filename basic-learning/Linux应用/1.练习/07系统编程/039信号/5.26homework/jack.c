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

//读rose消息
void read_msg(int sig)
{
    if(sig == SIGRTMIN)
    {
        char msg_r[SIZE];
        bzero(msg_r,SIZE);
        read(fd,msg_r,sizeof(msg_r));
        printf("from rose:%s \n",msg_r);
    }
}

//获取进程号
int pid()
{
	FILE *fp = popen("ps -e | grep \'rose\' | awk \'{print $1}\'", "r");//打开管道，执行shell 命令
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

int main(int argc,char **argv) 
{
    //1.判断管道文件是否存在
    printf("pid :%d \n",getpid());
    if(access(FIFO,F_OK))
    {
        int ret = mkfifo(FIFO,0666);
        if(ret == -1)
        {
            perror("mkfifo");
            return -1;
        }
    }
    //2.打开管道文件
    fd = open(FIFO,O_RDWR);
    if(-1 == fd)
    {
        perror("open \n");
        return -1;
    }
    //3.注册信号,读取新消息
    signal(SIGRTMIN,read_msg);
    char msg_w[SIZE];
    int pid ;
    printf("pid : ");
    scanf("%d",&pid);
    getchar();

    while(1)
    {
        bzero(msg_w,SIZE);
        printf("jack:");
        fgets(msg_w,SIZE,stdin);
        write(fd,msg_w,strlen(msg_w));

        kill(pid,SIGRTMAX);
    }

    return 0;
}