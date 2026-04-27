#include "client_list.h"

/* 初始化客户链表 */
CLIENT init_client_list(void)
{
	CLIENT head = malloc(sizeof(Client));
	if(head != NULL)
	{
		INIT_LIST_HEAD(&head->list);
	}
	return head;
}


//创建新节点
CLIENT new_client_node(	char ip[30],unsigned short port,int accept_fd)
{
	CLIENT new = malloc(sizeof(User));
	if(new != NULL)
	{
		strcpy(new->ip,ip );
        new->accept_fd = accept_fd;
        new->port = port;
		new->list.next = new->list.prev = NULL;
	}
	return new;
}

//尾插入节点
void tail_insert_client(CLIENT head, CLIENT new)
{
	list_add_tail(&(new->list), &(head->list));
}


//根据端口号查找client
CLIENT find_client(CLIENT head, unsigned short port)
{
	CLIENT p, q;
	list_for_each_entry_safe(p, q, &(head->list), list)
	{
		if(p->port==port )
			return p;
	}
	return NULL;
}

//根据端口号删除client节点
CLIENT delete_client(CLIENT head, unsigned short port)
{
	CLIENT p, q;
	list_for_each_entry_safe(p, q, &(head->list), list)
	{
		if(p->port==port )
		{
			list_del_init(&(p->list));
			return p;
		}		
	}

	return NULL;
}

//逆序打印链表
void reverse_client(CLIENT head)
{
	struct list_head *pos;
	CLIENT p;
	list_for_each_prev(pos, &(head->list))
	{
		p = list_entry(pos, Client, list);
		printf("username: %s ip:%s port:%d \n",p->username, p->ip, p->port);
	}
}

//遍历单个用户节点
void show_client_single(CLIENT single)
{
	printf("username: %s ip:%s port:%d\n", single->username,single->ip, single->port);
}

//遍历
void show_client(CLIENT head)
{
	CLIENT p;
	struct list_head *q;

	list_for_each(q, &(head->list))
	{
		p = list_entry(q, Client, list);
		printf("username: %s ip:%s port:%d \n",p->username, p->ip, p->port);
	}
	printf("\n");
}

void show_client_to_client(CLIENT head,int accept_fd)
{
	CLIENT p;
	struct list_head *q;
	char buf[100] = {0};
	list_for_each(q, &(head->list))
	{
		p = list_entry(q, Client, list);
		bzero(buf,100);
		sprintf(buf,"username: %s ip:%s port:%d \n",p->username, p->ip, p->port);
		write(accept_fd,buf,strlen(buf));
		printf("username: %s ip:%s port:%d \n",p->username, p->ip, p->port);
	}
	printf("\n");
}