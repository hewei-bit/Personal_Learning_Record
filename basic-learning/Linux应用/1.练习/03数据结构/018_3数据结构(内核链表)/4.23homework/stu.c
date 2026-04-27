/**************************
实现一个单链表，保存学生的姓名，学号，年龄。
要求：
输入1，新建节点保存一个学生的信息，并按照学号插入到链表中（学号按照升序排列）
输入2，再输入学号，找到该学生的信息节点，打印并删除
输入3，顺序打印链表中每位同学的信息
输入4，逆序打印链表中每位同学的信息
输入5，退出程序

时间：2020-4-23 
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _STU
{
    char name[10];
    int id;
    int age;
    struct _STU *next;
}StuNode,*STUNODE;

//初始化链表
STUNODE init_node(void)
{
    STUNODE head = malloc(sizeof(StuNode));
    if(head == NULL)
    {
        printf("init err \n");
        return NULL;
    }
    memset(head,0,sizeof(StuNode));
    head->next = head;
    return head;
}

//新节点
STUNODE new_node(char *name,int id,int age )
{
    STUNODE new = malloc(sizeof(StuNode));
    if(new == NULL)
    {
        printf("new err \n");
        return NULL;
    }
    new->age = age;
    new->id = id;
    strcpy(new->name,name);
    new->next = NULL;
}

//查找节点
STUNODE search_node(STUNODE head, int id)
{
    STUNODE p = head->next;
    while (p != head)
    {
        if(p->id == id)
            break;
        p = p->next;
    }
    return NULL;   
}

//删除节点
STUNODE del_node(STUNODE head,int id)
{
    STUNODE p = search_node(head,id);
    if(NULL == p)
        return NULL;
    while(head->next != p)
        head = head->next;

    head->next = p->next;
    p->next = NULL;

    return p;
}

//尾插
int tail_insert(STUNODE head, STUNODE new)
{
    STUNODE p =head;
    while(p->next != head)
        p = p->next;

    p->next = new;
    new->next = head;
    return 0;
}

//按学号插入链表
int insert_node(STUNODE head,STUNODE new)
{
    if(head->next == head)
    {
        head->next = new;
        new->next = head;
        return 0;
    }
    STUNODE p = head->next;
    STUNODE k = head;
    while(p->id <= new->id)
    {
        if(p->next == head)
        {
            p->next = new;
            new->next = head;
            return 0;
        }
        p = p->next;
    }

    while(k->next != p)
        k = k->next;

    new->next = p;
    k->next = new;
    return 0;
}

//按学号排序
int sort_id_node(STUNODE head)
{
    /* 链表中没有节点和只有一个节点时不需要排序 */
	if(head->next == head)
		return -1;
	if(head->next->next ==head)
		return -2;
	
	STUNODE p = head->next;
	STUNODE k = p->next;
    int min_id =0;
    //先求最小值
    while(k != head)
    {
        if(p->id > k->id)
            p = k;
        k = k->next;
        if(k == head)
            min_id = p->id;
    }
    p = del_node(head,p->id);
    tail_insert(head,p);
    p = head->next;
    k = p;
    //开始排序
    while(head->next->id != min_id)
    {
        while(k->id != min_id)
        {
            if(p->id > k->id)
                p = k;
            k = k->next;
            
        }
        p = del_node(head,p->id);
        tail_insert(head,p);
        p = head->next;
        k = p;
    }


    return 0;
}

//按学号排序
int sort_id_data(STUNODE head)
{
	/* 链表中没有节点和只有一个节点时不需要排序 */
	if(head->next == head)
		return -1;
	if(head->next->next == head)
		return -2;
	
	STUNODE p = head->next;
	STUNODE k = p->next;
	
	while(p->next != head)
	{
		while(k != head)
		{
			if(p->id > k->id)
			{
				STUNODE q;
				StuNode tmp = *k;
				*k = *p;
				*p = tmp;	
				
				q = k->next;
				k->next = p->next;
				p->next = q;
				
			}
			k = k->next;
		}
		p = p->next;
		k = p->next;
	}
	
	return 0;	
} 

//倒序打印
void show_reverse(STUNODE head,STUNODE p)
{
    if(p != head)
    {
        show_reverse(head,p->next);

        printf("学号:%5d 姓名: %5s年龄:%5d \n",p->id,p->name,p->age);
    }
        
}



//遍历
void show(STUNODE head)
{
    STUNODE p = head->next;
    while(p != head)
    {
        printf("学号:%5d 姓名: %5s年龄:%5d \n \n",p->id,p->name,p->age);
        p = p->next;
    }
}


int main()
{
    STUNODE head = init_node();
    if(head == NULL)
    {
        printf("list init err \n");
        return -1;
    }

    int id;
    int num;
    int age;
    char name[10] = {0};

    while(1)
    {
        printf("请输入选项\n");
        printf("输入1，新建节点保存一个学生的信息，并按照学号插入到链表中（学号按照升序排列）\n");
        printf("输入2，再输入学号，找到该学生的信息节点，打印并删除\n");
        printf("输入3，顺序打印链表中每位同学的信息\n");
        printf("输入4，逆序打印链表中每位同学的信息\n");
        printf("输入5，退出程序\n");
    
        scanf("%d",&num);
        switch (num)
        {
        case 1:
            printf("输入姓名 学号 年龄：\n");
            scanf("%s %d %d",name,&id,&age);
            STUNODE new = new_node(name,id,age);
            if(new == NULL)
            {
                printf("new node err \n");
                return -2;
            }
            insert_node(head,new);
            
            break;
        case 2:
            show(head);
            break;
        case 3:
            sort_id_data(head);
            show(head);
            break;
        case 4:
            show_reverse(head,head->next);
            break;
        case 5:
            return 0;

        default:
            printf("输入选项无效，请重新输入\n");   
            break;
        }
    }
    return 0;
}














