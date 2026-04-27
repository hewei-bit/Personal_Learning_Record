#include <stdio.h>
#include <strings.h>
#include <unistd.h>
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
	server_addr.sin_port = htons(50002);
	// 1、inet_addr
	//server_addr.sin_addr.s_addr = inet_addr("192.168.3.166");
	//2、inet_aton
	//inet_aton("192.168.3.166", &server_addr.sin_addr);
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
	
	/* 等待对方链接 */
	struct sockaddr_in client_addr;
	bzero(&client_addr, sizeof(client_addr));
	int size = sizeof(client_addr);
	int cfd_1 = accept(socket_fd, (struct sockaddr *)&client_addr, &size);
	if(cfd_1 == -1)
	{
		perror("accept");
		return -1;
	}
	printf("accept sucess\n");
	printf("[%s:%u]\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	
	while(1)
	{
		/* 数据收发 */
		char buf_write[10] = {0};
		printf("to client:");
		scanf("%s", buf_write);
		// ret = write(cfd_1, buf_write, 10);
        ret = send(cfd_1,buf_write,10,0);
		if(ret == -1)
		{
			perror("write");
			return -1;
		}
		
		printf("%d\n", __LINE__);
		
		char buf[10] = {0};
		// ret = read(cfd_1, buf, 10);
        ret = recv(cfd_1, buf, 10,0);
		if(ret == -1)
		{
			perror("read");
			return -1;
		}
		printf("from %s:%s\n", inet_ntoa(client_addr.sin_addr), buf);
	}
	
	
	/* 关闭套接字文件描述符 */
	close(cfd_1);
	close(socket_fd);
	
	return 0;
}