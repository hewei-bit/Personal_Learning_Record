#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>

struct sockaddr_in clint_addr;

int main() 
{
    /* 创建 套接字 */
	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_fd == -1)
	{
		perror("socket");
		return -1;
	}
	
	/* 加入多播组 */
	struct  ip_mreq  mreq;
	bzero(&mreq, sizeof(mreq));
	//指明组播IP地址
	mreq.imr_multiaddr.s_addr = inet_addr("224.0.0.5");
	//指明接收组播消息的IP地址
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);
	//利用刚才信息，将套接字加入组播组
	setsockopt(socket_fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq,  sizeof(mreq));



	/* 绑定IP地址和端口号 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50002);
	// 1、inet_addr
	//server_addr.sin_addr.s_addr = inet_addr("192.168.3.168");
	//2、inet_aton
	//inet_aton("192.168.3.168", &server_addr.sin_addr);
	//3、INADDR_ANY  代表主机的所有IP地址
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret == -1)
	{
		perror("bind");
		return -1;
	}
	printf("bind sucess\n");

    //定义send
    char buf[10] = {0};
    struct sockaddr_in send_addr;
    socklen_t len = sizeof(send_addr);
    while(1)
    {
        //数据收发
        bzero(buf,10);
        recvfrom(socket_fd,buf,10,0,(struct sockaddr *)&send_addr,&len);
        printf("from [%s:%d]:%s \n ",inet_ntoa(send_addr.sin_addr),ntohs(send_addr.sin_port),buf);

    }

    //关闭套接字
    shutdown(socket_fd,2);

    return 0;
}

