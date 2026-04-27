#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <signal.h>

void sighandler(int sig)
{
    printf("%d \n",__LINE__);
    printf("sig : %d\n",sig);
}

int main(void)
{
    //信号SIGINT注册一个函数
    signal(SIGINT,sighandler);

    pid_t mypid = getpid();

    kill(mypid,SIGINT);

    sleep(20);



    return 0;
}