/********************************
	实现双向循环链表的基本操作
********************************/
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

/* 结构体模板定义  */
struct node 
{
	int data;
	struct node *next;
	struct node *prve;
};

struct node1 
{
	float data;
	struct node1 *next;
	struct node1 *prve;
};

/* 初始化一个带有头节点的链表 */
struct node *init_list(void)
{
	struct node *head = malloc(sizeof(struct node));
	if(!head)
	{
		printf("堆内存申请失败！\n");
		return NULL;
	}
	
	head->next = head->prve = head;

	return head;
}

/* 新建节点 */
struct node *new_node(int data)
{
	struct node *new = malloc(sizeof(struct node));
	if(!new)
	{
		printf("堆内存申请失败！\n");
		return NULL;
	}
	
	new->next = new->prve = NULL;
	new->data = data;
	return new;
}

/* 将新节点插入到任意节点之后 */
void ins_next(struct node *p, struct node *new)
{
	new->prve = p;
	new->next = p->next;
	p->next = new;
	new->next->prve = new;
}


/* 查找节点 */
struct node *find_node(struct node *head, int data)
{
	struct node *p = head->next;
	while(p != head)
	{
		if(p->data == data)
			return p;
		p = p->next;
	}
	
	return NULL;	
}


/* 删除链表中的节点 */
struct node *del_node(struct node *p)
{
	p->prve->next = p->next;
	p->next->prve = p->prve;
	p->next = p->prve = NULL;
	
	return p;
}

/* 移动节点,将值为src的节点移动到值为dest的节点之后 */
int mv_node(struct node *head, int src, int dest)
{
	struct node *k = find_node(head, dest);
	if(k == NULL)
	{
		printf("目标节点不存在！\n");
		return -1;
	}
	
	struct node *p = find_node(head, src);
	if(p == NULL)
	{
		printf("要移动的节点不存在！\n");
		return -2;
	}
	p = del_node(p);
	
	ins_next(k , p);
	
	return 0;
}

/* 遍历链表 */
void show(struct node *head)
{
	struct node *p = head->next;
	while(p != head)
	{
		printf("data:%d\n", p->data);
		p = p->next;
	}
}

int main(int argc, char *argv[]) 
{ 
	struct node *head = init_list();
	if(head == NULL)
		return -1;

	struct node *new = new_node(10);
	if(new == NULL)
		return -1;
	ins_next(head, new);
	

	new = new_node(20);
	if(new == NULL)
		return -1;
	ins_next(head->next, new);
	
	new = new_node(30);
	if(new == NULL)
		return -1;
	ins_next(head->next, new);
	
	show(head);
	
	int ret = mv_node(head, 20, 10);
	if(ret == 0)
		show(head);
	
	return 0; 
} 