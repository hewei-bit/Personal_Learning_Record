#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc,char **agrv)
{
    
    pid_t pid  = fork();
    //从子进程进入
    if(pid == 0)
    {
        /* int ret = execl("./hello","hello","-s",NULL);
        if(ret == -1)
        {
            perror("execl");
        } */
        /* char *arr[] = {"hello","-s",NULL};
        int ret = execv("../hello",arr);
        if(ret == -1)
        {
            perror("execv");
        }  */
        char *envp[] = {"./"};
		int ret = execle("hello","hello","-s", NULL, envp);
		if(ret == -1)
		{
			perror("execle");
		}
        //这个返回值会被跳过
        exit(10);
    }
    //进入父进程
    if(pid > 0)
    {
        int num =0;
        waitpid(pid,&num,0);
        printf("num : %d \n",num);
        printf("exit:%d \n",WEXITSTATUS(num));
    }
    return 0;
}