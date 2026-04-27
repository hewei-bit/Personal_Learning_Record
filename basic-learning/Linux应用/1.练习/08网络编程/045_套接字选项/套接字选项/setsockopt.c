#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
	int ret;
	
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
	struct sockaddr_in server_addr, client_addr;
	socklen_t len = sizeof(server_addr);
	bzero(&server_addr, sizeof(server_addr));
	bzero(&client_addr, sizeof(client_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[1]));
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//server_addr.sin_addr.s_addr = inet_addr("192.168.14.203");
	int bind_ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(bind_ret == -1)
	{
		perror("bind() failed:");
		return -1;
	}
	printf("bind() is success\n");
	

	
	ret = listen(socket_fd, 2);
	if(ret == -1)
	{
		perror("listen");
		return -1;
	}
	printf("listen sucess\n");
	
	len = sizeof(client_addr);
	int accept_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &len);
	if(accept_fd == -1)
	{
		perror("accept");
		return -1;
	}
	printf("[%s-->%u] is online\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	
	/* 设置接收缓冲区大小 缓冲区有限值，太小不行，太大不行
	int size = 1;
	ret = setsockopt(accept_fd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size));
	if(ret == -1)
	{
		perror("setsockopt");
		return -1;
	}
	*/
	/* 设置接收缓冲区下限 缓冲区中的数据要达到下限值才可以触发操作事件*/
	int size = 3;
	ret = setsockopt(accept_fd, SOL_SOCKET, SO_RCVLOWAT, &size, sizeof(size));
	if(ret == -1)
	{
		perror("setsockopt");
		return -1;
	}
	
	/* 设置接收超时时间，如果在这个时间以内没有数据来就返回*/
	struct timeval mytime;
	mytime.tv_sec = 5;
	mytime.tv_usec = 0;
	ret = setsockopt(accept_fd, SOL_SOCKET, SO_RCVTIMEO, &mytime, sizeof(mytime));
	if(ret == -1)
	{
		perror("setsockopt");
		return -1;
	}
	while(1)
	{
		char buf[10] = {0};
		//ret = read(cfd_1, buf, 10);
		ret = recv(accept_fd, buf, 10, 0);
		if(ret == -1)
		{
			perror("recv");
		}
		printf("from %s:%s\n", inet_ntoa(client_addr.sin_addr), buf);
	}
	
	return 0;
}