#include "user.h"

//初始化链表
USER init_user_list(void)
{
	USER head = malloc(sizeof(User));
	if(head != NULL)
	{
		INIT_LIST_HEAD(&(head->list));
		return head;
	}
	return NULL;
}

//创建新节点
USER new_user_node(char *username, char * password)
{
	USER new = malloc(sizeof(User));
	if(new != NULL)
	{
		strcpy(new->username,username );
		strcpy(new->password,password);
		new->list.next = new->list.prev = NULL;
		return new;
	}
	return NULL;
}

//尾插入节点
void tail_insert_user(USER head, USER new)
{
	list_add_tail(&(new->list), &(head->list));
}



//根据用户名查找用户
USER find_user(USER head, char *username)
{
	USER p, q;
	list_for_each_entry_safe(p, q, &(head->list), list)
	{
		if(strcmp(p->username,username) == 0)
			return p;
	}
	return NULL;
}

//根据用户名删除用户节点
USER delete_user(USER head, char *username)
{
	USER p, q;
	list_for_each_entry_safe(p, q, &(head->list), list)
	{
		if(strcmp(p->username,username) == 0)
		{
			list_del_init(&(p->list));
			return p;
		}		
	}

	return NULL;
}

//逆序打印链表
void reverse_user(USER head)
{
	struct list_head *pos;
	USER p;
	list_for_each_prev(pos, &(head->list))
	{
		p = list_entry(pos, User, list);
		printf(L_PURPLE"username:%s password:%s \n", p->username, p->password);
	}
}

//遍历单个用户节点
void show_user_single(USER single)
{
	printf(L_PURPLE"username:%s password:%s \n", single->username, single->password);
}

//遍历
void show_user(USER head)
{
	USER p;
	struct list_head *q;

	list_for_each(q, &(head->list))
	{
		p = list_entry(q, User, list);
		printf(L_PURPLE"username:%s password:%s \n", p->username, p->password);
	}
	printf("\n");
}