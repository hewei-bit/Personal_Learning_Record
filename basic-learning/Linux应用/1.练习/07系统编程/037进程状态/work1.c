#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
     printf("请输入一个数字：\n");
    int b ;
    scanf("%d",&b);

    pid_t pid = fork();
    //从子进程进入
    if(pid ==0)
    {
        int a = 0;
        printf("请输入一个数字：\n");
        scanf("%d",&a);
        while(1)
        {
            sleep(1);
            if(b > a)
                exit(0);
            printf("LINE : %d \n",__LINE__);
        }
    }
    // 
    if(pid > 0)
    {
        while(1)
    {
        sleep(1);
        printf("LINE : %d \n",__LINE__);
    }
            
    }
    return 0;
}