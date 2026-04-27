#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <pthread.h>

// void * fun (void * arg)
// {
// 	int fd = (int )arg;
// 	char buf[10]  = {0};
// 	while(1)
// 	{
// 		/* 数据收发 */
// 		char buf[10] = {0};
// 		recvfrom(fd,buf,10,0,NULL,NULL);
// 		printf("from server:%s\n", buf);
// 	}

// }

int main(void)
{
	int ret;
	/* 创建 UNIX域套接字 */
	int socket_fd = socket(AF_LOCAL, SOCK_DGRAM, 0);
	if(socket_fd == -1)
	{
		perror("socket");
		return -1;
	}

	// pthread_t tid;
	// pthread_create(&tid,NULL,fun,(void *)socket_fd);

	/* 绑定IP地址和端口号 */
	struct sockaddr_un server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sun_family = AF_LOCAL;
	strcpy(server_addr.sun_path,"/home/hewei/mysocket");
	// int ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	// if(ret == -1)
	// {
	// 	perror("bind");
	// 	return -1;
	// }
	// printf("bind sucess\n");
	
	struct sockaddr_un client_addr;
	bzero(&client_addr,sizeof(client_addr));
	
	char buf[10] = {0};
	while(1)
	{
		/* 数据收发 */
		char buf_write[10] = {0};
		printf("to SERVER:");
		scanf("%s", buf_write);
		ret = sendto(socket_fd, buf_write, 10,0,(struct sockaddr *)&server_addr,sizeof(server_addr));
		if(ret == -1)
		{
			perror("write");
			return -1;
		}
		
		printf("%d\n", __LINE__);
		
		// char buf[10] = {0};
		// socklen_t len = sizeof(server_addr);
		// ret = recvfrom(socket_fd, buf, 10,0,(struct sockaddr *)&server_addr,&len);
		// if(ret == -1)
		// {
		// 	perror("read");
		// 	return -1;
		// }
		// printf("%s",buf);
	}
	
	
	/* 关闭套接字文件描述符 */

	close(socket_fd);
	
	return 0;

}