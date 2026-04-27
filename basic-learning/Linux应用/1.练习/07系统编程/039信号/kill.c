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
	
	pid_t pid = fork();
	if(pid == 0)	//子进程进入
	{
		//signal(SIGKILL, SIG_IGN);	//设置忽略信号
		//signal(SIGKILL, fun);			//设置自定义动作
		signal(SIGINT, fun);
		signal(SIGUSR1, fun);
		signal(SIGUSR2, fun);
		int i = 0;
		pause();
		while(1)
		{	
			printf("s_pid:%d, i:%d\n", getpid(), i++);
			sleep(1);
		}
		
	}
	if(pid > 0)		//父进程进入
	{
		sleep(5);
		int ret = kill(pid, SIGINT);
		ret = kill(pid, SIGUSR1);
		ret = kill(pid, SIGUSR2);
		//kill(getpid(), SIGINT);  // 自己给自己发送信号
		raise(SIGINT);
		if(ret == -1)
		{
			perror("kill");
			return -1;
		}
		printf("signal send\n");
	}


	
	return 0;
}