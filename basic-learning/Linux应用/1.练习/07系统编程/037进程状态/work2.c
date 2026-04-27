#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc,char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    
    //printf("输入两个整数：\n");
    //scanf("%d %d",&a,&b);
    pid_t pid = fork();
    
    //子进程
    if(pid == 0)
    {
        exit(a+b);
    }
    //父进程
    if(pid > 0)
    {
         int status;
        waitpid(pid,&status,0);
        printf("%d \n",WIFEXITED(status));
        printf("%d \n",WEXITSTATUS(status));
        //printf("%d \n",c);
    }
}