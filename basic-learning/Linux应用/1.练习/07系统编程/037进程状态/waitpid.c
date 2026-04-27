#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    int a = 10;

    pid_t pid = fork();

    if(pid == 0)
    {
        printf("my pid: %d,pid:%d,   %d \n",getpid(),pid,__LINE__);
        sleep(3);
        printf("my pid: %d,pid:%d,   %d \n",getpid(),pid,__LINE__);

    }
    if(pid > 0)
    {
        waitpid(pid,&a,WNOHANG);
        printf("a: %d\n",a);
        printf("%d \n",WEXITSTATUS(a));
    }


    return 0;
}