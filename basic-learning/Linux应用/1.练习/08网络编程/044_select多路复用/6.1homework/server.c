/* *********************************
***data:2020-6-1
***
***name:
 **********************************/


#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	/* if(argc != 2)
	{
		printf("./server [htons]\n");
		return -1;
	} */
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
	bzero(&server_addr, sizeof(server_addr));
	bzero(&client_addr, sizeof(client_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50004);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int bind_ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(bind_ret == -1)
	{
		perror("bind() failed:");
		return -1;
	}
	printf("bind() is success\n");
	
	/* 将待连接套接字设置为监听套接字，并设置最大同时接收连接请求个数 */
	int listen_ret = listen(socket_fd, 2);
	if(listen_ret == -1)
	{
		printf("listen() failed");
		return -1;
	}
	printf("listen() is success\n");
	
	/* 等待对端连接请求 */
	socklen_t len = sizeof(client_addr);
	int accept_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &len);
	if(accept_fd == -1)
	{
		perror("accept() failed");
		return -1;
	}
	printf("accept() success!\n");
	
	/* 接收文件名 */
	char filename[10] = {0};
	int r_size = read(accept_fd, filename, 10);
	printf("r_size:%d\n", r_size);
	printf("filename:%s\n", filename);
	
	int file_fd = open(filename, O_RDWR|O_CREAT, 0777);
	if(file_fd == -1)
	{
		perror("open() failed:");
		return -1;
	}
	printf("open() %s success\n",filename);
	
	
	/* 接收文件 */
	int r, w;
	int nr = 0;
	char r_buf[100] = {0};
	while(1)
	{
		bzero(r_buf,100);
		r = read(accept_fd, r_buf, sizeof(r_buf));
		if(r == 0)
		{
			break;
		}
		nr += r;
		printf("read() %d byte\n", nr);
		
		w = write(file_fd, r_buf, r);
		if(w == -1)
		{
			perror("write() failed");
			return -1;
		}
		
	}
	
	
	/* 收发消息 */
	/*  while(1)
	{
		char w_buf[10] = {0};
		printf("server:");
		fgets(w_buf, sizeof(w_buf), stdin);
		write(accept_fd, w_buf, strlen(w_buf));
		
		char r_buf[10] = {0};
		read(accept_fd, r_buf, sizeof(r_buf));
		printf("from client:%s\n", r_buf);
	}  */

	close(accept_fd);
	close(socket_fd);
	
	return 0;
}