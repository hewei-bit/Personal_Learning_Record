#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
	int ret;
	char hostname[20] = {0};
	gethostname(hostname, 20);
	printf("hostname:%s\n", hostname);
	
	/* 创建套接字 */
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1)
	{
		perror("socket() failed:");
		return -1;
	}
	printf("socket() is success\n");
	
	
	
	/* 绑定IP地址和端口号 */
	struct sockaddr_in server_addr, client_addr;
	socklen_t len = sizeof(server_addr);
	bzero(&server_addr, sizeof(server_addr));
	bzero(&client_addr, sizeof(client_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[1]));
	// server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_addr.s_addr = inet_addr("192.168.3.166");
	int bind_ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(bind_ret == -1)
	{
		perror("bind() failed:");
		return -1;
	}
	printf("bind() is success\n");
	/* 监听 */
	ret = listen(socket_fd, 2);
	if(ret == -1)
	{
		perror("listen");
		return -1;
	}
	printf("listen sucess\n");
	/* 链接 */	
	len = sizeof(client_addr);
	int accept_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &len);
	if(accept_fd == -1)
	{
		perror("accept");
		return -1;
	}
	printf("[%s-->%u] is online\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	
	/* 获取本地的IP和端口 */
	struct sockaddr_in s_addr;
	
	bzero(&s_addr, sizeof(s_addr));
	ret = getsockname(accept_fd, (struct sockaddr *)&s_addr, &len);
	if(ret == -1)
	{
		perror("getsockname");
		return -1;
	}
	printf("[%s-->%u]\n", inet_ntoa(s_addr.sin_addr), ntohs(s_addr.sin_port));
	
	/* 获取对端的IP和端口 */
	struct sockaddr_in c_addr;
	bzero(&c_addr, sizeof(c_addr));
	ret = getpeername(accept_fd, (struct sockaddr *)&c_addr, &len);
	if(ret == -1)
	{
		perror("getpeername");
		return -1;
	}
	printf("[%s-->%u]\n", inet_ntoa(c_addr.sin_addr), ntohs(c_addr.sin_port));
	
	

	sleep(10);
	return 0;
}