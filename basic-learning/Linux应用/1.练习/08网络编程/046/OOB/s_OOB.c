#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>


int accept_fd;

/* 带外数据接收处理 */
void fun(int sig)
{
    printf("line:%d\n",__LINE__);
    char buf[10] = {0};
    recv(accept_fd,buf,10,MSG_OOB);
    fprintf(stderr,"buf:%s,%d \n",buf,__LINE__);
    printf("line:%d\n",__LINE__);
}

int main(int argc, char **argv)
{

	
	/* 创建套接字 */
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1)
	{
		perror("socket() failed:");
		return -1;
	}
	printf("socket() is success\n");
	
	/* 设置端口重用 */
	int on = 1;
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	
	/* 绑定IP地址和端口号 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	socklen_t len = sizeof(server_addr);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50002);
	// 1、inet_addr
	server_addr.sin_addr.s_addr = inet_addr("192.168.3.168");
	//2、inet_aton
	//inet_aton("192.168.3.166", &server_addr.sin_addr);
	//3、INADDR_ANY  代表主机的所有IP地址
	// server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret == -1)
	{
		perror("bind");
		return -1;
	}
	printf("bind sucess\n");
	
	
	ret = listen(socket_fd, 2);
	if(ret == -1)
	{
		perror("listen");
		return -1;
	}
	printf("listen sucess\n");


	struct sockaddr_in client_addr;
	bzero(&client_addr, sizeof(client_addr));
	len = sizeof(client_addr);
	accept_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &len);
	if(accept_fd == -1)
	{
		perror("accept");
		return -1;
	}
	printf("[%s-->%u] is online\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	
	/* 接收到带外数据就发信号 */
    fcntl(accept_fd,F_SETOWN,getpid());
    /* 注册信号 */
    signal(SIGURG,fun);

	while(1)
	{
		char buf[10] = {0};
		//ret = read(cfd_1, buf, 10);
		ret = recv(accept_fd, buf, 10, 0);
		printf("from %s:%s\n", inet_ntoa(client_addr.sin_addr), buf);
		
	}
	
	return 0;
}