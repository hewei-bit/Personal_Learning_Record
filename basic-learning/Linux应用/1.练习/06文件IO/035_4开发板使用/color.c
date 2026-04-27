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
    //打开显示屏文件
    int fd = open("/dev/fb0",O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    
    //将数据写进文件
   /*
    int buf[800*480] = {0};
    int i;

    for(i = 0;i < 800*480/3;i++)
    {
        buf[i] = 0x00ff0000;
    }
    for(i = 800*480/3;i < 2*800*480/3;i++)
    {
        buf[i] = 0x0000ff00;
    }
    for(i = 2*800*480/3;i < 800*480;i++)
    {
        buf[i] = 0x000000ff;
    }*/
    int col[3] = {red,green,blue};
    int buf[800*480] = {0};
    int j = 0;
    int i = 0;
    int k = 0;
    for (j = 0; j < 480; j++)
    {
        for(i = j;i < j*800/3;i++)
        {
            buf[i] = red;
        }
        for(i = j*800/3;i < j*2*800/3;i++)
        {
            buf[i] = green;
        }
        for(i = j*2*800/3;i < j*800;i++)
        {
            buf[i] = blue;
        }
    }
    
    

    int ret = write(fd,buf,800*480*4);
    if(ret == -1)
    {
        perror("write");
        return -1;
    }

    //关闭文件
    close(fd);


    return 0;
}