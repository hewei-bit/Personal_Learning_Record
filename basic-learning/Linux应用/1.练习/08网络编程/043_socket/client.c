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
	server_addr.sin_port = htons(50002);
	server_addr.sin_addr.s_addr = inet_addr("192.168.3.166");
	int ret = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret == -1)
	{
		perror("connect");
		return -1;
	}
	
	while(1)
	{
		/* 读写数据 */
		char buf[10] = {0};
		read(socket_fd, buf, 10);
		printf("buf:%s\n", buf);
		
		char buf_write[10] = {0};
		printf("to server:");
		scanf("%s", buf_write);
		write(socket_fd, buf_write, 10);
	}
	
	
	/* 关闭套接字文件描述符 */
	close(socket_fd);
	
	return 0;
}