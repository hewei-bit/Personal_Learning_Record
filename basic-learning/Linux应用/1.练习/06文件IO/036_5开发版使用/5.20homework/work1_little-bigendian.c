#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


#define green 0x0000ff00
#define red 0x00ff0000
#define blue 0x000000ff

int main()
{
    char buf[800*480*3] = {0};
    //打开显示屏文件
    int fd = open("2.bmp",O_RDWR);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
    lseek(fd,54,SEEK_SET);

    int ret = read(fd,buf,800*480*3);
    if(ret == -1)
    {
        perror("read");
        return -1;
    }
    
   printf("%d  %d  %d \n",buf[0],buf[1],buf[2]);
    

    //关闭文x件
    close(fd);


    return 0;
}