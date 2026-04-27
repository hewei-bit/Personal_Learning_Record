#include "main.h"
//图形界面
#include "GUI.h"
//文件IO
#include "IO.h"
//用户和client
#include "user.h"
#include "client_list.h"

CLIENT head = NULL;

//发消息
bool sen_msg(char *msg, unsigned short port)
{
	struct list_head *pos;
	struct client *tmp;
	char buf[40] = {0};
    list_for_each(pos, &head->list)
	{
		tmp = list_entry(pos, struct client, list);
		if(tmp->port == port)
		{
            sprintf(buf,"%s-->%d:%s",tmp->ip,tmp->port,msg);
			write(tmp->accept_fd, buf, strlen(buf));
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

    //读写buf
	char r_msg[100] = {0};
	char w_msg[100] = {0};
    char name_buf[20] = {0};
    char file_buf[20] = {0};
    char msg[100] = {0};
    // 1, 初始化一个带有 5 条线程的线程池
    thread_pool *pool = malloc(sizeof(thread_pool));
    init_pool(pool, 5);
    
    // 销毁线程池
    destroy_pool(pool);

	//初始化client头节点
	head = init_client_list();


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
	

    //组播设置
    /* 创建 套接字 */
	int socket_udp_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_udp_fd == -1)
	{
		perror("socket");
		return -1;
	}
	
	/* 设置可以发送组播 */
	int on = 1;
	setsockopt(socket_udp_fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));

	
	/* 设定广播地址和端口号 */
	struct sockaddr_in recv_addr;
	bzero(&recv_addr, sizeof(recv_addr));
	recv_addr.sin_family = AF_INET;
	recv_addr.sin_port = htons(50003);
	recv_addr.sin_addr.s_addr = inet_addr("255.255.255.255");
	

//创建套接字
    int socket_group_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(socket_group_fd == -1)
    {
        perror("socket");
        return -1;
    }

    // 设定组播地址和端口号
    struct sockaddr_in recv_group_addr;
    bzero(&recv_group_addr,sizeof(recv_group_addr));
    recv_group_addr.sin_family = AF_INET;
    recv_group_addr.sin_port = htons(50004);
    recv_group_addr.sin_addr.s_addr = inet_addr("224.0.0.5");









	/* 等待对端连接请求 */
	socklen_t len = sizeof(client_addr);
	int accept_fd = -1;
	
	/* 定义文件描述符集合，并且清空 */
	fd_set set;
	FD_ZERO(&set);
	int maxfd = socket_fd;
	struct list_head *pos, *n;
	struct client *tmp, *temp,*tempp;
	char *str = NULL;
	
	while(1)
	{

		FD_SET(socket_fd, &set);//将监听套接字加入集合
		FD_SET(STDIN_FILENO, &set);
        maxfd = maxfd > STDIN_FILENO ? maxfd : STDIN_FILENO;

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

        /* 监听每个客户端 */
		list_for_each_safe(pos, n, &head->list)
		{
			temp = list_entry(pos, struct client, list);

			if(FD_ISSET(temp->accept_fd, &set))//客户端发送消息过来
			{
                bzero(name_buf,20);
				bzero(msg, 100);
				read(temp->accept_fd, msg, sizeof(msg));

                if(strncmp(msg, "first time",10) == 0)//客户端初次上线
                {
                    printf("%s\n",msg);
                    int j = 0;
                    for(int i = 0;i < sizeof(msg);i++)
                    {
                        if(msg[i] == '[')
                        {
                            i++;
                            while(msg[i] != ']')
                            {
                                name_buf[j] = msg[i];
                                i++;
                                j++;
                            }
                            break;
                        }
                    }
                    // printf("%s\n",name_buf);
                    strcpy(temp->username,name_buf);//将用户名加入链表

                    //广播上线
                    /* 发送广播数据 */
                    sendto(socket_udp_fd, msg, 10, 0, (struct sockaddr *)&recv_addr, sizeof(recv_addr));
                    
                }

				if(strncmp(msg, "goodbye", 7) == 0)//客户端下线
				{

                    //广播下线
                    /* 发送广播数据 */
                    bzero(msg,100);
                    sprintf(msg,"%s 正在下线",temp->username);
                    sendto(socket_udp_fd, msg, 10, 0, (struct sockaddr *)&recv_addr, sizeof(recv_addr));
					close(temp->accept_fd);
					list_del(&temp->list);
					printf("[%s][%s-->%u] 正在下线\n",temp->username, temp->ip, temp->port);
                 
                }

                if(strncmp(msg, "show_all",8) == 0)//实现客户端查询功能
                {
                    show_client_to_client(head,temp->accept_fd);
                }

                if(strncmp(msg, "file", 4) == 0)//文件传输(未完成)
                {
                    printf("%s",msg);
                    int j = 0;
                    int nCount = 0;
                    bzero(name_buf,20);
                    bzero(file_buf,20);

                    //分析用户名和文件名
                    for(int i = 0;msg[i] != '\r' ;i++)
                    {
                        if(0 == nCount)
                        {
                            if ('-' == msg[i])
                            {
                                nCount++;
                            }
                        }
                        if(1 == nCount) //第一个'-'
                        {
                            name_buf[j] = msg[i];
                            j++;
                            if ('-' == msg[i])
                            {
                                name_buf[--j] = '\0';
                                nCount++;
                                j = 0;
                            }
                        }
                        else if (2 == nCount) //第二个'-'
                        {
                            file_buf[j] = msg[i];
                            j++;	
                            if ('-' == msg[i])
                            {
                                file_buf[--j] = '\0';
                                nCount++;
                                j = 0;
                            }		
                        }
                        printf("%s\n",name_buf);
                        printf("%s\n",file_buf);

                        //找到传输目标
                        int destination_fd = 0;
                        list_for_each(pos, &head->list)
                        {
                            tmp = list_entry(pos, struct client, list);
                            if(strcmp(tmp->username,name_buf) ==0 )
                            {
                                destination_fd = tmp->accept_fd;
                            }
                        }

                        	/* 接收转发文件 */
                        int r, w;
                        int nr = 0;
                        char r_buf[100] = {0};
                        while(1)
                        {
                            bzero(r_buf,100);
                            r = read(socket_fd, r_buf, sizeof(r_buf));
                            if(r == 0)
                            {
                                break;
                            }
                            nr += r;
                            printf("read() %d byte\n", nr);
                            
                            w = write(destination_fd, r_buf, r);
                            if(w == -1)
                            {
                                perror("write() failed");
                                break;
                            }
                        }
                    }
                }

				if((str = strstr(msg, ":")) != NULL)//转发消息
				{
                    bzero(name_buf,sizeof(name_buf));
                    for(int i = 0;i < sizeof(msg);i++)
                    {
                        if(msg[i] == ':')
                            break;
                        name_buf[i] = msg[i];
                    }
                    bzero(r_msg,100);
                    sprintf(r_msg,"%s",name_buf);
                    printf("%s....\n",   name_buf);


                    unsigned short port = 0;
                    
                    CLIENT p;
                    struct list_head *q;
                   
                    list_for_each(q, &(head->list))
                    {
                        p = list_entry(q, Client, list);
                        if(strcmp(p->username,name_buf) == 0)
                        {
                            printf("%s\n",p->username);
                            port = p->port;
                            break;
                        }
                        
                    }
                    
					
					if(!sen_msg(str+1, port))//str+1表示去除端口号
					{
						printf("%u is not found\n", port);//没有找到端口号，打印错误
					}
				}

                if(strncmp(msg, "group", 5) == 0)//实现群聊(未完成)
                {
                    // 发送组播数据
                    char buf[100] = {0};
                    bzero(buf,100);
                    read(socket_fd,buf,100);
                    sendto(socket_group_fd,buf,100,0,(struct sockaddr *)&recv_group_addr,sizeof(recv_group_addr));
                }

			}
		}

        if(FD_ISSET(STDIN_FILENO, &set))//输入消息,服务器下线
        {
            bzero(w_msg, 100);
            fgets(w_msg, 100, stdin);
            // write(socket_fd, w_msg, strlen(w_msg));
            if(strncmp(w_msg, "exit", 4) == 0)
                break;
        }

	}

/* 关闭套接字文件描述符 */
    close(socket_group_fd);
    close(socket_udp_fd);
	close(accept_fd);
	close(socket_fd);
	
	return 0;
}
