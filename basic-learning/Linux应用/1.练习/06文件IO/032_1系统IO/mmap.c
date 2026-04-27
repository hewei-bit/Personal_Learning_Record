#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc,char **argv)
{
    int fd,fd1,fd2;
    int ret;
    int read_buf[10000] = {0};

    //打开读取文件
    fd1 = open("b.txt",O_RDWR);
    if(fd1 ==-1)
    {
        printf("open  err\n");
        return -1;
    }
    printf("fd1 :%d\n",fd1);

    char *p = mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
    if(p == (void*) -1)
    {
        printf("mmap err\n");
        return -1;
    }
    printf("p: %p\n",p);
    printf("p : %s\n",p);
    
    memset(p,0,100);

    //memset(p,0,100);
    munmap(p,100);

    //关闭文件
    ret = close(fd1);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }

    return 0;
}


