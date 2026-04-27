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
	if(argc != 2)
	{
		printf("./client [htons] [ip]\n");
		return -1;
	} 
	
	/* 创建套接字 */
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1)
	{
		perror("socket() failed:");
		return -1;
	}
	printf("socket() is success!");
	
	/* 连接服务器 */
	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(50004);
	server_addr.sin_addr.s_addr = inet_addr("192.168.14.203");
	socklen_t len = sizeof(server_addr);
	int connect_ret = connect(socket_fd, (struct sockaddr *)&server_addr, len);
	if(connect_ret == -1)
	{
		perror("connect() failed:");
		return -1;
	}
	printf("connect() is success!\n");
	
	/* 发送文件名 */
	printf("filename:%s\n", argv[1]);
	int w_size = write(socket_fd, argv[1], 10);
	printf("w_size:%d\n", w_size);
	
	/* 打开文件 */
	int file_fd = open(argv[1], O_RDWR);
	if(file_fd == -1)
	{
		perror("open() failed");
		return -1;
	}
	
	
	/* 发送文件 */
	int r, w;
	int nw = 0;
	char r_buf[100] = {0};
	
	while(1)
	{
		r = read(file_fd, r_buf, sizeof(r_buf));
		if(r == 0)
		{
			break;
		}
		
		w = write(socket_fd, r_buf, r);
		
		nw += w;
		printf("write() %d byte\n", nw);
	}
	
	
	
	
	/* 收发消息 */
	/* while(1)
	{
		char r_buf[10] = {0};
		
		read(socket_fd, r_buf, sizeof(r_buf));
		printf("from server:%s\n", r_buf);
		
		char w_buf[10] = {0};
		
		printf("client:");
		fgets(w_buf, sizeof(w_buf), stdin);
		write(socket_fd, w_buf, strlen(w_buf));	
	}  */
	close(file_fd);
	close(socket_fd);
	
	return 0;
}