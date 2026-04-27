//任务1.开机动画

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

#define green 0x0000ff00
#define red 0x00ff0000
#define blue 0x000000ff

int show_bmp_any(char *pathname,int x,int y,int width,int higth)
{
    //限定大小
    if(x+width>800 || y+higth>480)
    {
        printf("err \n");
        return -1;
    }
    //初始化数组
    char buf_bmp[width*higth*3] ;
    int  buf_lcd[width*higth] ;
    int buf_temp[width*higth] ;//翻转时使用

    //打开图片文件
    int fd_bmp = open(pathname,O_RDWR);
    if(fd_bmp < 0)
    {
        perror("open");
        return -1;
    }

    //打开显示屏文件
    int fd_show = open("/dev/fb0",O_RDWR);
    if( fd_show< 0)
    {
        perror("open");
        return -1;
    }
    //偏移54字节
    lseek(fd_bmp,54,SEEK_SET);
    //读取数据
    read(fd_bmp,buf_bmp,width*higth*3);

    //转换数据
    int i=0;
    for(i=0;i<width*higth;i++)
        buf_lcd[i] = buf_bmp[3*i+2]<<16 | buf_bmp[3*i+1]<<8 | buf_bmp[3*i];
    //按行翻转
    int j,k;
    for(k=0; k<higth; k++)
		for(j=0; j<width; j++)
			buf_temp[(higth-k-1)*width+j] = buf_lcd[k*width+j];

    //内存映射
    int *mmap_bmp = mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,fd_show,0);
    for(j= 0;j<higth;j++)
    {
        for(k=0;k<width;k++)
        {
            *(mmap_bmp+(j+y)*800+k+x) = buf_temp[j*width+k];
        }
    }
    munmap(mmap_bmp,800*480*4);

    //关闭文件
    close(fd_show);
    close(fd_bmp);

}

int show_bmp(char *pathname)
{
    unsigned char buf_bmp[800*480*3]={0};
    int  buf_lcd[800*480];
    int buf_temp[800*480];//翻转时使用

    //打开图片文件
    int fd_bmp = open(pathname,O_RDWR);
    if(fd_bmp < 0)
    {
        perror("open");
        return -1;
    }

    //打开显示屏文件
    int fd_show = open("/dev/fb0",O_RDWR);
    if( fd_show< 0)
    {
        perror("open");
        return -1;
    }
    //偏移54字节
    lseek(fd_bmp,54,SEEK_SET);
    //读图片信息
    int ret;
    ret = read(fd_bmp,buf_bmp,800*480*3);
    if(ret== -1)
    {
        perror("read");
        return -1;
    }

    //将RGB格式数据写入24位ARGB格式中
    int i =0;
    for(i = 0;i<800*480;i++)
    {
        buf_lcd[i] = buf_bmp[3*i+2]<<16 | buf_bmp[3*i+1]<<8 | buf_bmp[3*i];
    }
    int x,y;
    
    //按行翻转
    for(x = 0;x<800;x++)
    {
        for(y=0;y<480;y++)//单列上下翻转
        {
            buf_temp[(479-y)*800+x] = buf_lcd[y*800+x];
        }
    }
    /* //按字节数写
     ret = write(fd_show,buf_temp,800*480*4);
    if(ret== -1)
    {
        perror("write");
        return -1;
    }*/
    //内存映射
   
    int *mmap_bmp = mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,fd_show,0);
    for(i=0;i<800*480;i++)
        *(mmap_bmp+i) = buf_temp[i];

    munmap(mmap_bmp,800*480*4);
//关闭文件
    close(fd_bmp);
    close(fd_show);
    return 0;
}

int main()
{
    int a=10;
    int i=0;
    while(a>0)
    {
        for(i=1;i<12;i++)
        {
            char bmp[10] = {0};
            sprintf(bmp,"photo/%d.bmp",i);   
            show_bmp(bmp);
            sleep(1);
        }
        printf("a: %d \n",a);
        a-=1;
    }
    return 0;
}