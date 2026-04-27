#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc,char ** argv)
{
    if(argc < 4)
    {
        printf("请输入 目标ip地址  端口号  要复制的文件");
        return -1;
    }
    //系统IO打开文件
    int fd = open(argv[3],O_RDONLY,0777);
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

    //绑定IP和端口号
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
    int ret = bind(socket_fd,(struct sockaddr *)&server_addr,sizeof(server_addr));
    if(ret == -1)
    {
        perror("bind");
        return -1;
    }
    printf("bind success \n");

    //设置监听,这个套接字只负责链接
    ret = listen(socket_fd,2);
    if(ret == -1)
    {
        perror("listen error \n");
        return -1;
    }
    printf("listen success \n");

    //等待对方连接
    struct sockaddr_in client_addr;
    bzero(&client_addr,sizeof(client_addr));
    int size = sizeof(client_addr);
    int  cfd_1 = accept(socket_fd,(struct sockaddr *)&client_addr,&size);
    if(cfd_1 == -1)
    {
        perror("accpet");
        return -1;
    }
    printf("accept success \n");
    printf("[%s:%d]\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

    char buf[10] = {0};
    while(1)
    {    
        //从文件中读数据
        
        ret = read(fd,buf,sizeof(buf));
        if(ret == -1)
        {
            perror("read");
            return -1;
        }
        
        //如果ret==0代表读完了
        if(ret == 0)
        {
            break;
        }
        
        //数据发送

        ret = write(cfd_1,buf,ret);
        if(ret ==  -1)
        {
            perror("write");
            return -1;
        } 
        // printf("%d \n", __LINE__);
    }

    // 关闭套接字文件描述符
    close(cfd_1);
    close(socket_fd);
    //关闭文件
    close(fd);

    return 0;
}