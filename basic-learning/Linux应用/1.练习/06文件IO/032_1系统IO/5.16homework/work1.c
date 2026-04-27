#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    //打开一个文件
    int fd_a = open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
    if(fd_a == -1)  
    {
        printf("open err\n");
        return -1;   
    }  
    printf("a.txt fd_a:%d\n",fd_a);

    //写入数据
    char buf_write[20] = {"hewei is learning"};
    int ret = write(fd_a,buf_write,strlen(buf_write));
    printf("write ret:%d\n",ret);

    //将文件位置偏移量移至文件开头
    int num = lseek(fd_a,0,SEEK_CUR);
    if(num == -1)
    {
        printf("lseek err\n");
        return -1;
    }

    //文件中按字节读取数据
    int buf_read[20] = {0};
    ret = read(fd_a,buf_read,sizeof(buf_read));
    if(-1 == ret)
    {
        printf("read err\n");
        return -1;
    }

    //关闭文件
    ret = close(fd_a);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }

    return 0;
}









