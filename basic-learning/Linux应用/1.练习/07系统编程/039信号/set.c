#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void fun(int sig)
{
	printf("pid:%d, sig:%d\n", getpid(), sig);
}


/* 父进程给子进程发送信号 */
int main(void)
{
	int i = 1;
	
	/* 将信号加进一个信号集  */
	sigset_t set;
	sigemptyset(&set);	//清空信号集
	
	for(i; i<65; i++)
	{
		if(i == 32 || i == 33 || i == 9 || i == 19)
			continue;
		
		signal(i, fun);
		sigaddset(&set, i);
	}
	
	/* 将信号集中的信号设置阻塞 */
	sigprocmask(SIG_BLOCK, &set, NULL);
	
	for(i=1; i<65; i++)
	{
		if(i == 32 || i == 33 || i == 9 || i == 19)
			continue;
		
		raise(i);
	}
	
	printf("send signal over\n");
	
	sleep(2);
	
	/* 解除阻塞 */
	sigprocmask(SIG_UNBLOCK, &set, NULL);
	
	sleep(2);
	
	return 0;
}