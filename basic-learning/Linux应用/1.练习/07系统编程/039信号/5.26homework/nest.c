//////////////////////////////////////////////////////////////////////////
//
//相同信号不嵌套（在前一个信号处理完毕之后才会执行），不相同信号要嵌套。
//
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fun(int sig)
{
    int count = 5;
    if(sig == SIGUSR1)
    {
        while(count >0)
        {
            fprintf(stderr,"a");
            sleep(1);
            count--;
        }
    }
    if(sig == SIGUSR2)
    {
        while(count >0)
        {
            fprintf(stderr,"b");
            sleep(1);
            count--;
        }
    }
    if(sig == SIGHUP)
    {
        while(count >0)
        {
            fprintf(stderr,"c");
            sleep(1);
            count--;
        }
    }
}

int main(int argc,char **argv)
{
    signal(SIGUSR1,fun);
    signal(SIGUSR2,fun);
    signal(SIGHUP,fun);
    printf("pid : %d \n",getpid());
    while(1)
    {
        pause();
    }
    return 0;
}