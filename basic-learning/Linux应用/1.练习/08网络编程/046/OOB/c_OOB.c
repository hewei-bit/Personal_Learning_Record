#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int main(int argc, char **argv)
{
	// if(argc != 3)
	// {
	// 	printf("%s [htons] [ip]\n", argv[0]);
	// 	return -1;
	// } 
	
	/* 创建套接字 */
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1)
	{
		perror("socket() failed:");
		return -1;
	}
	printf("socket() is success!\n");
	
	/* 连接服务器 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	// server_addr.sin_port = htons(atoi(argv[1]));
	// server_addr.sin_addr.s_addr = inet_addr(argv[2]);
	server_addr.sin_port = htons(50002);
	// server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_addr.s_addr = inet_addr("192.168.3.168");
	socklen_t len = sizeof(server_addr);
	int connect_ret = connect(socket_fd, (struct sockaddr *)&server_addr, len);
	if(connect_ret == -1)
	{
		perror("connect() failed:");
		return -1;
	}
	printf("connect() is success!\n");
	
	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	int ret = getpeername(socket_fd, (struct sockaddr *)&addr, &len);
	if(ret == -1)
	{
		perror("getpeername");
		return -1;
	}
	printf("[%s-->%u]\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
	
	/* 定义文件描述符集合，并且清空 */
	fd_set set;
	FD_ZERO(&set);
	int maxfd = socket_fd;
	
	char r_msg[100] = {0};
	char w_msg[100] = {0};
	
	while(1)
	{
		bzero(w_msg, 100);
		scanf("%s", w_msg);
		// fgets(w_msg, 100, stdin);
		send(socket_fd, w_msg, strlen(w_msg), 0);
		send(socket_fd, w_msg, strlen(w_msg), MSG_OOB);
		if(strncmp(w_msg, "exit", 4) == 0)
			break;
	}

	close(socket_fd);
	
	return 0;
}