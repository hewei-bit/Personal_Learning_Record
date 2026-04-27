#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int front(int i,int fd_a);
int tail(int i,int fd_a);    


int front(int i,int fd_a)
{
    i = i*10;
    lseek(fd_a,0,SEEK_SET);
    lseek(fd_a,i,SEEK_SET);
    char buf_w[10] = {"123456789\n"};
    write(fd_a,buf_w,10);
    sleep(1);
    return 0;
}
int tail(int i,int fd_a)
{
      
    i = i*10;
    lseek(fd_a,0,SEEK_SET);
    lseek(fd_a,100+i,SEEK_SET);
    char buf_w[10] = {"abcdefghi\n"};
    write(fd_a,buf_w,10);
    sleep(1);
    return 0;
}
int main()
{
    int fd_a = open("test.txt",O_RDWR|O_CREAT,0777);
    if (fd_a == -1)
    {
        printf("打开失败\n");
        return -1;
    }
    int i = 0;
    for(i;i<10;i++)
    {
        tail(i,fd_a);
        front(i,fd_a);
        printf("i:%d",i);
    }
}
