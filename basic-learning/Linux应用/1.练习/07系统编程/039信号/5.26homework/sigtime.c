//////////////////////////////////////////////////////////////////////////
//
//在没有及时响应相同非实时信号时后面的信号会被丢弃,实时信号不会被丢弃.
//
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void f(int sig)
{
	if(sig == SIGRTMIN)
	{
		printf("signal is SIGUSR1\n");
	}
}


int main()
{
    signal(SIGRTMIN,f);

    sigset_t sig;
    sigemptyset(&sig);
    sigaddset(&sig,SIGRTMIN);

    sigprocmask(SIG_BLOCK,&sig,NULL);

    printf("pid:%d \n",getpid());

    int i =20;
    while(i--)
	{
		printf("%d\n", i);
		sleep(1);
	}
	
	sigprocmask(SIG_UNBLOCK, &sig, NULL);//解阻塞
	
	while(1)
	{
		pause();
	}

    return 0;
}