#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


#include <sys/wait.h>
#include <sys/types.h>

int  main(void)
{
	/* 创建无名管道 */
	int pipefd1[2] = {0};  // 父进程 --》 子进程
	int ret = pipe(pipefd1);
	if(ret == -1)
	{
		perror("pipe");
		return -1;
	}
	close(pipefd1[0]);
	
	/* 创建子进程 */
	pid_t pid = fork();
	if(pid < 0)
	{
		printf("fork error");
		exit(1);
	}
	else if(pid > 0)   // 父进程
	{
		
		/* 有写者 有数据 
		write(pipefd1[1], "123456", 6);	
		sleep(5);
		*/
		
		/* 有写者，无数据 
		sleep(5);
		*/
		
		/* 无写者， 有数据
		write(pipefd1[1], "123456", 6);
		close(pipefd1[1]);
		sleep(2);
		 */
		 
		/* 无写者，无数据 
		close(pipefd1[1]);
		*/
		
		ret = write(pipefd1[1], "123456", 6);
		printf("ret:%d\n", ret);
		if(ret == -1)
		{
			perror("write");
		}
	}
	else 				//子进程
	{
		
	}
	
	
	return 0;
}