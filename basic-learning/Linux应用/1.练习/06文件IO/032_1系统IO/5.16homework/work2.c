#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char **argv)
{
    if (argc != 3)
    {
        printf("请输入程序 字符串 文件名\n");
    }


    //打开一个文件
    int fd_a = open(argv[2],O_RDWR|O_CREAT,0777);
    if(fd_a == -1)  
    {
        printf("open err\n");
        return -1;   
    }  
    printf("a.txt fd_a:%d\n",fd_a);

    //写入数据
    int ret = write(fd_a,argv[1],strlen(argv[1]));
    printf("write ret:%d\n",ret);

    //将文件位置偏移量移至文件开头
    int num = lseek(fd_a,0,SEEK_SET);
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
    printf("%s",buf_read);

    //关闭文件
    ret = close(fd_a);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }



    return 0;
}