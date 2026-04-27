#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
   int  fd_a = open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
    if(fd_a == -1)
    {
        printf("open err\n");
        return -1;
    }
    printf("fd_a:%d\n",fd_a);
    
    int fd_b = dup(fd_a);
     
      printf("fd_b:%d\n",fd_b);
    //写数据
    write(fd_a,"123123",6);

    char buf_read[10] = {0};
    printf("size:%lu\n",read(fd_b,buf_read,6));
    printf("buf_read:%s\n",buf_read);

    //关闭文件
    int ret = close(fd_a);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }
    ret = close(fd_b);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }
    return 0;
}
