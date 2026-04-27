#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    //打开一个文件
    int fd_a = open("a.txt",O_RDWR|O_CREAT,0777);
    if(fd_a == -1)
    {
        printf(" open err\n");
        return -1;
    }
    printf("a.txt fd_a :%d\n",fd_a);

    //读取文件内容
    char buf_read[20] = {0};
    int ret= read(fd_a,buf_read,sizeof(buf_read));
    printf("buf_read:%s\n",buf_read);

//移动文件位置指针
    int  num = lseek(fd_a,-1,SEEK_SET);
    printf("num : %d\n",num);
    
    //将数据写入文件
    char buf_write[23] = {"12312321"};
    ret = write(fd_a,buf_write,strlen(buf_write));

    char buf_read2[20] = {0};
    ret= read(fd_a,buf_read2,sizeof(buf_read2));
    printf("buf_read:   %s\n",buf_read2);

    //关闭文件
    ret = close(fd_a);
    if(-1 == ret)
    {
        printf("close err\n");
        return -1;
    }

    return 0;
}