#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char ** argv)
{
    // if(argc < 4)
    // {
    //     printf("请输入 目标ip地址  端口号  要接受的文件\n");
    //     return -1;
    // }

    int fd = open(argv[3],O_CREAT|O_RDWR|O_TRUNC,0777);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
    printf("open %s success \n",argv[3]);

    //创建套接字
    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        perror("socket");
        return -1;
    }

    //链接服务器
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    int duankou  = atoi(argv[2]);
    server_addr.sin_port = htons(duankou);
    //1.inet_aton()
    // inet_aton("192.168.3.166", &server_addr.sin_addr);
    //2.inet_addr()
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    //3.INADDR_ANY
    // server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = connect(socket_fd,(struct sockaddr *)&server_addr,sizeof(server_addr));
    if(ret == -1)
    {
        perror("connect");
        return -1;
    }
    printf("connect success \n");

    int buf[100] = {0};
    while(1)
    {
        //数据读写
        ret = read(socket_fd,buf,sizeof(buf));
        if(ret == -1)
        {
            perror("read");
            return -1;
        }

        if(ret == 0)
        {
            break;
        }
        printf("%d \n", __LINE__);

        ret = write(fd,buf,ret);
        if(ret ==  -1)
        {
            perror("write");
            return -1;
        }
    }

    // 关闭套接字文件描述符
    close(socket_fd);
    close(fd);
    return 0;
}