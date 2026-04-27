#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



int main()
{
    // int i = 10;
    // int fd = open("a.txt",O_RDWR|O_CREAT,0777);
    // if(fd == 0)
    // {
    //     printf("open err \n");
    //     return 0;
    // }

    // pid_t pid = fork();
    // if(pid ==0)
    // {
    //     while(1)
    //     {
    //         printf("请输入一个数字：\n");
    //         int b ;
    //         scanf("%d",&b);
    //         if(b > a)
    //             break;
    //         else
    //         {
    //             printf("continue \n");
    //         }
            
    //     }
    //     printf("i: %d \n",i);
    //     printf("my pid: %d,pid:%d,   %d \n",getpid(),pid,__LINE__);
    //     //write(fd,"123",3);
    // }
    // if(pid>0)
    // {
    //     int a = 20;
    //     printf("i: %d \n",i);
    //     printf("my pid: %d,pid:%d,   %d \n",getpid(),pid,__LINE__);
    //     // sleep(2);
    //     // lseek(fd,0,SEEK_SET);
    //     // char buf[5] = {0};
    //     // read(fd,buf,5);
    //     // printf("buf : %s \n",buf);
    // }
    // printf("my pid: %d,pid:%d,   %d \n",getpid(),pid,__LINE__);

    printf("%d: before fork() ... \n",getpid());

    pid_t pid = fork();

    printf("%d: after fork() ... \n",getpid());

    return 0;
}