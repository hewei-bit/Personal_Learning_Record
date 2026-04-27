#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sighandler(int sig)
{
    fprintf(stderr,"catch a signal : %d \n",sig);
}

int main(int argc,char  **argv) 
{
    sigset_t set;
    sigemptyset(&set);
    int i;
    for(i = SIGHUP;i<SIGRTMAX;i++)
    {
        if(i == SIGKILL || i == SIGSTOP)
            continue;
        signal(i,sighandler);//为信号i设置响应函数
        sigaddset(&set,i);//将信号i添加到信号集中
    }

    printf("[%d]:blocked for a while \n",getpid());
    sigprocmask(SIG_BLOCK,&set,NULL);//阻塞所有信号
    sleep(10);
    
    printf("[%d]:unblocked all aignals \n",getpid());
    sigprocmask(SIG_UNBLOCK,&set,NULL);//让开所有阻塞

    return 0;
}

