#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
	/* 创建 套接字 */
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1)
	{
		perror("socket");
		return -1;
	}
	
	/* 链接服务器 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50003);
	server_addr.sin_addr.s_addr = inet_addr("192.168.3.168");
	int ret = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret == -1)
	{
		perror("connect");
		return -1;
	}
	
	/* 文件描述符集合 */
	fd_set set;
	int maxfd = 0;
	
	while(1)
	{
		FD_ZERO(&set);	//清空文件描述符集合
		FD_SET(socket_fd, &set); 	//将套接字的文件描述符加入到文件描述符集合
		FD_SET(STDIN_FILENO, &set);	//将标准输入的文件描述符加入到文件描述符集合
		maxfd = socket_fd > STDIN_FILENO?socket_fd:STDIN_FILENO;
		
		//如果套接字的文件描述符和标准输入的文件描述符发送动作该函数返回
		select(maxfd+1, &set, NULL, NULL, NULL); 
		printf("%d\n", __LINE__);
		
		//套接字的文件描述符在set中，表示刚才套接字发生动作了，需要去读取socket_fd数据
		if(FD_ISSET(socket_fd, &set)) 
		{
			char buf[10] = {0};
			//read(socket_fd, buf, 10);
			int ret = recv(socket_fd, buf, 10, 0);
			printf("ret:%d, buf:%s\n", ret, buf);
		}
		
		//标准输入的文件描述符在set中，表示刚才套接字发生动作了，需要去读取STDIN_FILENO数据
		if(FD_ISSET(STDIN_FILENO, &set)) 
		{
			char buf_write[10] = {0};
			scanf("%s", buf_write);
			//write(socket_fd, buf_write, 10);
			send(socket_fd, buf_write, 10, 0);
		}
		
	}
	
	
	/* 关闭套接字文件描述符 */
	// close(socket_fd);
	shutdown(socket_fd, 2);
	
	return 0;
}