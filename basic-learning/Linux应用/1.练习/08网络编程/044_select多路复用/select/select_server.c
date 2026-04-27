#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
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
	
	/* 绑定IP地址和端口号 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50003);
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
	
	/* 设置监听 这个套接字只负责链接 */
	ret = listen(socket_fd, 2);
	if(ret == -1)
	{
		perror("listen");
		return -1;
	}
	printf("listen sucess\n");
	
	
	
	
	/* 文件描述符集合 */
	fd_set set;
	int maxfd = 0;
	int c_fd[20] = {0};
	int c_num = 0;
	struct sockaddr_in client_addr;
	bzero(&client_addr, sizeof(client_addr));
	
	while(1)
	{
		/* 数据收发 */
		FD_ZERO(&set);	//清空文件描述符集合
		//将套接字的文件描述符加入到文件描述符集合
		for(int i=0; i<c_num; i++)
		{
			FD_SET(c_fd[i], &set);
			maxfd = maxfd > c_fd[i]?maxfd:c_fd[i];
		}
		
		FD_SET(STDIN_FILENO, &set);	//将标准输入的文件描述符加入到文件描述符集合
		maxfd = maxfd > STDIN_FILENO?maxfd:STDIN_FILENO;
		
		FD_SET(socket_fd, &set);	//将监听套接字的文件描述符加入到文件描述符集合
		maxfd = maxfd > socket_fd?maxfd:socket_fd;
		
		//如果套接字的文件描述符和标准输入的文件描述符发送动作该函数返回
		select(maxfd+1, &set, NULL, NULL, NULL); 
		printf("%d\n", __LINE__);
		
		//套接字的文件描述符在set中，表示刚才套接字发生动作了，需要去读取cfd_1数据
		for(int i = 0; i<c_num; i++)
		{
			if(FD_ISSET(c_fd[i], &set)) 
			{
				char buf[10] = {0};
				//ret = read(cfd_1, buf, 10);
				ret = recv(c_fd[i], buf, 10, 0);
				if(ret == -1)
				{
					perror("read");
					return -1;
				}
				printf("from %s:%s\n", inet_ntoa(client_addr.sin_addr), buf);
				break;
			}
		}
		
		
		//标准输入的文件描述符在set中，表示刚才套接字发生动作了，需要去读取STDIN_FILENO数据
		// if(FD_ISSET(STDIN_FILENO, &set)) 
		// {
			// char buf_write[10] = {0};
			// scanf("%s", buf_write);
			// ret = write(cfd_1, buf_write, 10);
			// int ret = send(cfd_1, buf_write, 10, 0);
			// if(ret == -1)
			// {
				// perror("send");
			// }
			// printf("send data\n");
		// }
		
		//监听套接字的文件描述符在set中，表示刚才套接字发生动作了，有人来链接了
		if(FD_ISSET(socket_fd, &set)) 
		{
			/* 等待对方链接 */
			int size = sizeof(client_addr);
			int cfd_1 = accept(socket_fd, (struct sockaddr *)&client_addr, &size);
			if(cfd_1 == -1)
			{
				perror("accept");
				return -1;
			}
			printf("accept sucess\n");
			printf("[%s:%u]\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
			c_fd[c_num++] = cfd_1;
			sleep(10);
		}
		
	}
	
	
	/* 关闭套接字文件描述符 */
	// close(cfd_1);
	// close(socket_fd);
	//shutdown(cfd_1, 2);
	shutdown(socket_fd, 2);
	
	
	return 0;
}