#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

int main()
{
    //创建管道
    int pipefd[2] = {0};
    int ret = pipe(pipefd);
    if(ret == -1)
    {
        printf("pipe error \n");
        return -1;
    }

    //创建子进程
    pid_t pid  = fork();
    if(pid < 0)
    {
        printf("fork error \n");
        return -1;
    }
    else if(pid > 0)//父进程
    {
        int num = 0;
        while(1)
        {
            //往管道里写数据
        /* 有写者，有数据 */
            ret = write(pipefd[1],"123456",6);
            num += ret;
            printf("num: %d \n",num);
            printf("my pid : %d write over \n",getpid());
        }
        //等待子进程
        // wait(NULL);
        //从管道读数据
        // char buf_2[7] = {0};
        // read(pipefd[0],buf_2,6);
        // printf("my pid : %d read over \n",getpid());
        // printf("%s \n",buf_2);
    }
    else//子进程
    {
        
        //从管道读数据
        char buf[7] = {0};
        bzero(buf,11);

        read(pipefd[0],buf,6);
        //printf("my pid : %d read over \n",getpid());
        printf("%s \n",buf);
      
        //sleep(1);
        //往管道里写数据
        // write(pipefd[1],"byebye",6);
        // printf("my pid : %d write over \n",getpid());
        // exit(0);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
