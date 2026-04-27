#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

#define green 0x0000ff00
#define red 0x00ff0000
#define blue 0x000000ff

int main()
{
    //打开显示屏文件
    int fd = open("/dev/fb0",O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    
    
    char buf[800*480*4] = {0};
    int i;
    for (i = 0;i<800*480*4;i+=4)
    {
        buf[i] = 0x00;
        buf[i+1] = 0xff;
        buf[i+2] = 0x00;
        buf[i+3] = 0x00;
    }
    /*
    int ret = write(fd,buf,800*480*4);
    if(ret == -1)
    {
        perror("write");
        return -1;
    }*/
    char *mmap_bmp = mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    for(i = 0;i <800*480*4;i++)
        *(mmap_bmp+i)=buf[i];
    //关闭文x件
    close(fd);


    return 0;
}