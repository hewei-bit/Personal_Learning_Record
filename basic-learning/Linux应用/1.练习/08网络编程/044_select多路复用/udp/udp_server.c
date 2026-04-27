#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

struct sockaddr_in client_addr;

void * fun (void * arg)
{
	int fd = (int )arg;
	char buf[10]  = {0};
	while(1)
	{
		/* 数据收发 */
		char buf[10] = {0};
		
		socklen_t size = sizeof(client_addr);
		recvfrom(fd,buf,10,0,(struct sockaddr *)&client_addr,&size);
		printf("from client : %s \n",buf);
	}
}


int main(void)
{
	
	/* 创建 套接字 */
	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_fd == -1)
	{
		perror("socket");
		return -1;
	}

	pthread_t tid;
	pthread_create(&tid,NULL,fun,(void *)socket_fd);

	
	/* 绑定IP地址和端口号 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50002);
	// 1、inet_addr
	//server_addr.sin_addr.s_addr = inet_addr("192.168.3.166");
	//2、inet_aton
	//inet_aton("192.168.3.166", &server_addr.sin_addr);
	//3、INADDR_ANY  代表主机的所有IP地址
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret == -1)
	{
		perror("bind");
		return -1;
	}
	printf("bind sucess\n");

	char buf[10] = {0};
	while(1)
	{
		/* 数据收发 */
		bzero(buf,10);
		printf("to client ");
		scanf("%s",buf);

		ret = sendto(socket_fd,buf,10,0,(struct sockaddr *)&client_addr, sizeof(client_addr));
		if(ret == -1)
		{
			perror("send to");
			return -1;
		}
	}
	
	/* 关闭套接字文件描述符 */

	shutdown(socket_fd,2);
	
	return 0;
} 