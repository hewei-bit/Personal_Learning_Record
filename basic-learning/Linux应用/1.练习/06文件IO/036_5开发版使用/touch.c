#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <linux/input.h>

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

void touch(int *x,int *y)
{
    //打开触摸屏设备文件
    int fd = open("/dev/input/event0",O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return;
    }
    int tmp_x=0,tmp_y=0;
    //自己定义input_event结构体
    struct input_event buf;

    while(1)
    {
        read(fd,&buf,sizeof(buf));
        if(buf.type == EV_ABS && buf.code == ABS_X)
        {
            tmp_x = buf.value;
        }
        if(buf.type == EV_ABS && buf.code == ABS_Y)
        {
            tmp_y = buf.value;
        }
        if(tmp_x != 0 && tmp_y !=0)
        {
            *x = tmp_x;
            *y = tmp_y;
            break;
        }  
    }
    close(fd); 
}

int main()
{
    int x,y;
    while(1)
    {
        show_bmp_any("2.bmp",100,100,200,200);
        touch(&x,&y);
        printf("x:%d,y:%d \n",x,y);

        if(x>100 && x<300 && y > 100 && y < 300)
            show_bmp("1.bmp");
    }
    return 0;
}