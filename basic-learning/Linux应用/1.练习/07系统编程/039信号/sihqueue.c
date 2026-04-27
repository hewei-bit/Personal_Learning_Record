#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void fun(int sig, siginfo_t *info, void *p)
{
	if(info->si_code == SI_QUEUE)
		printf("pid:%d, sig:%d, data:%d\n", getpid(),sig, info->si_int);
	if(info->si_code == SI_USER)
		printf("pid:%d, sig:%d, data:%d\n", getpid(),sig, info->si_int);
}

/* 父进程给子进程发送信号和数据 */
int main(void)
{
	pid_t pid = fork();
	if(pid == 0)	//子进程进入
	{
		int i = 0;
		//捕捉一个指定信号
		//定义捕捉结构体
		struct sigaction act;
		bzero(&act, sizeof(act));
		//扩展信号响应函数指针
		act.sa_sigaction = fun;
		//使用扩展信号响应函数而不是标准响应函数
		act.sa_flags |= SA_SIGINFO;
		sigaction(SIGINT, &act, NULL);

		while(1)
		{	
			printf("s_pid:%d, i:%d\n", getpid(), i++);
			sleep(1);
		}
		
	}
	if(pid > 0)		//父进程进入
	{
		//向子进程发送信号和数据,
		sleep(5);
		//定义信号携带额外数据的联合体
		union sigval test;
		test.sival_int = 108;
		int ret = sigqueue(pid, SIGINT, test);
		// kill(pid, SIGINT);
		printf("signal send\n");
	}


	
	return 0;
}