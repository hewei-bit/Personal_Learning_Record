#include "head.h"

struct client
{
	char ip[30];
	unsigned short port;
	int accept_fd;
	struct list_head list;//内核链表小结构体
};//分号

struct client *head = NULL;


/* 初始化链表 */
struct client *init_list(void)
{
	struct client *head = malloc(sizeof(struct client));
	if(head != NULL)
	{
		INIT_LIST_HEAD(&head->list);
	}
	return head;
}

//发消息
bool sen_msg(char *msg, unsigned short port)
{
	struct list_head *pos;
	struct client *tmp;
	list_for_each(pos, &head->list)
	{
		tmp = list_entry(pos, struct client, list);
		if(tmp->port == port)
		{
			write(tmp->accept_fd, msg, strlen(msg));
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("%s [htons]\n", argv[0]);
		return -1;
	} 
	
	//初始化头节点
	head = init_list();
	
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
	server_addr.sin_port = htons(atoi(argv[1]));
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
	int accept_fd = -1;
	
	/* 定义文件描述符集合，并且清空 */
	fd_set set;
	FD_ZERO(&set);
	int maxfd = socket_fd;
	struct list_head *pos, *n;
	struct client *tmp, *temp;
	char *str = NULL;
	char msg[100] = {0};
	
	while(1)
	{
		FD_SET(socket_fd, &set);//将监听套接字加入集合
		
		/* 遍历链表，将所有已连接的套接字添加到集合中 */
		list_for_each(pos, &head->list)
		{
			tmp = list_entry(pos, struct client, list);
			//printf("[%s-->%u]--->[%d] is online\n", tmp->ip, tmp->port, __LINE__);
			FD_SET(tmp->accept_fd, &set);
			maxfd = maxfd > tmp->accept_fd ? maxfd : tmp->accept_fd;		
		}
		
		/* 检测集合中发生动作的文件描述符 */
		select(maxfd+1, &set, NULL, NULL, NULL);
		if(FD_ISSET(socket_fd, &set))//有客户端上线
		{
			accept_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &len);
			printf("[%s-->%u] is online\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
			
			/* 创建新节点 */
			struct client *new = calloc(1, sizeof(struct client));
			if(new != NULL)
			{
				strcpy(new->ip, inet_ntoa(client_addr.sin_addr));
				new->port = ntohs(client_addr.sin_port);
				new->accept_fd = accept_fd;
			}
			/* 添加到链表中 */
			list_add_tail(&new->list, &head->list);		
		}
		list_for_each_safe(pos, n, &head->list)
		{
			temp = list_entry(pos, struct client, list);
			if(FD_ISSET(temp->accept_fd, &set))//客户端发送消息过来哦
			{
				bzero(msg, 100);
				read(temp->accept_fd, msg, sizeof(msg));
				if(strncmp(msg, "exit", 4) == 0)//客户端下线
				{
					close(temp->accept_fd);
					list_del(&temp->list);
					printf("[%s-->%u] is offline\n", temp->ip, temp->port);
				}
				if((str = strstr(msg, ":")) != NULL)//发消息
				{
					unsigned short port = atoi(msg);
					if(!sen_msg(str+1, port))//str+1表示去除端口号
					{
						printf("%u is not found\n", port);//没有找到端口号，打印错误
					}
				}
			}
		}
	}

	close(accept_fd);
	close(socket_fd);
	
	return 0;
}