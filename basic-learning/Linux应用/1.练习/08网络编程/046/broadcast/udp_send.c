#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <strings.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>


int main(void)
{
	/* 创建 套接字 */
	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_fd == -1)
	{
		perror("socket");
		return -1;
	}
	
	/* 设置可以发送广播 */
	int on = 1;
	setsockopt(socket_fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));

    /* 设置端口重用 */
	on = 1;
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	
	/* 设定广播地址和端口号 */
	struct sockaddr_in recv_addr;
	bzero(&recv_addr, sizeof(recv_addr));
	recv_addr.sin_family = AF_INET;
	recv_addr.sin_port = htons(50002);
	recv_addr.sin_addr.s_addr = inet_addr("255.255.255.255");
	
	char buf[10] = {0};
	while(1)
	{
		/* 发送广播数据 */
		bzero(buf, 10);
		printf("to recv:");
		scanf("%s", buf);
		sendto(socket_fd, buf, 10, 0, (struct sockaddr *)&recv_addr, sizeof(recv_addr));
	}
	
	/* 关闭套接字文件描述符 */
	shutdown(socket_fd, 2);
	
	return 0;
}