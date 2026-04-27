#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc,char **argv)
{
    //检查输入有效性
    if(argc != 3)
    {
        printf("输入程序名 要复制的文件 复制后的文件名\n");
        return -1;
    }


    //声明变量
    int fd1,fd2;
    int ret;
    

    //打开读取文件
    fd1 = open(argv[1],O_RDONLY,0777);
    if(fd1 ==-1)
    {
        printf("open %s err\n",argv[1]);
        return -1;
    }
    printf("fd1 :%d\n",fd1);


    //打开写入文件
    fd2 = open(argv[2],O_CREAT|O_RDWR|O_EXCL,0777);
    if(fd1 ==-1)
    {
        printf("open %s err\n",argv[2]);
        return -1;
    }
    printf("fd2 :%d\n",fd2);




    //循环从argv[1]读取，写入argv[2]

    int read_buf[10000] = {0};
    while(1)
    {
        //开始读
        ret = read(fd1,read_buf,sizeof(read_buf));
        if(ret == -1)
        {    
            printf("read %s err",argv[1]);
            break;
        }
        //如果ret==0代表读完了
        if(ret == 0)
        {
            break;
        }

        //读到多少写多少
        ret = write(fd2,read_buf,ret);
        if(ret == -1)
        {    
            printf("read %s err",argv[2]);
            break;
        }
        printf("read_buf :%ls\n",read_buf);
    }


    //关闭文件
    ret = close(fd1);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }
    //关闭文件
    ret = close(fd2);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }

    return 0;
}


