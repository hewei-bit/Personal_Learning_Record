#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>

struct sockaddr_in clint_addr;


int main(void)
{
	
	/* 创建 套接字 */
	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_fd == -1)
	{
		perror("socket");
		return -1;
	}
	
	/* 绑定IP地址和端口号 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50002);
	// 1、inet_addr
	//server_addr.sin_addr.s_addr = inet_addr("192.168.14.203");
	//2、inet_aton
	//inet_aton("192.168.14.203", &server_addr.sin_addr);
	//3、INADDR_ANY  代表主机的所有IP地址
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret == -1)
	{
		perror("bind");
		return -1;
	}
	printf("bind sucess\n");
	

	char buf[10];
	struct sockaddr_in send_addr;
	socklen_t size = sizeof(send_addr);
	while(1)
	{
		/* 数据收发 */
		bzero(buf, 10);
		recvfrom(socket_fd, buf, 10, 0, (struct sockaddr *)&send_addr, &size);
		printf("form [%s:%d]:%s\n", inet_ntoa(send_addr.sin_addr), ntohs(send_addr.sin_port), buf);
	}
	
	
	/* 关闭套接字文件描述符 */
	shutdown(socket_fd, 2);
	
	
	return 0;
}

