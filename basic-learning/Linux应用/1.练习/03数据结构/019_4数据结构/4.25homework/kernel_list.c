/*****************************
	使用内核链表，实现一个保存学生的姓名，学号，年龄的链表
要求：
输入1，新建节点保存一个学生的信息，并按照学号插入到链表中（学号按照升序排列）
输入2，再输入学号，找到该学生的信息节点，打印并删除
输入3，顺序打印链表中每位同学的信息
输入4，逆序打印链表中每位同学的信息
输入5，退出程序
时间：2020-4-24
作者：向俊灵
***************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct student
{
	char name[20];
	int sno;
	int age;
	struct list_head list;
	
}stu, *sList;


sList init_list();//初始化链表
sList new_node(char *str, int sno, int age);//创建新节点
void tail_insert(sList head, sList new);//尾插入节点
int sort_insert(sList head, sList new);//按学号从小到大插入学生节点
sList find_stu(sList head, int sno);//根据学号查找学生节点
sList delete_stu(sList head, int sno);//根据学号删除学生节点
void show_stu_single(sList single);//遍历单个学生节点
void show_list(sList head);//遍历
void reverse_stu(sList head);//逆序打印链表



int main(int argc, char const *argv[])
{
	sList head = init_list();
	sList new, temp, del;
	char name[20] = {0};
	int sno, age, n;

	while(1)
	{
		printf("\n");
		printf("-------function selection----------:\n");
		printf("1-----------创建一个学生，顺序插入链表\n");
		printf("2-----------输入学号，打印改学生信息，并删除\n");
		printf("3-----------顺序打印学生信息\n");
		printf("4-----------逆序打印学生信息\n");
		printf("5-----------退出程序\n");

		scanf("%d", &n);
		switch(n)
		{
			case 1:
					printf("\ninput the info:\n");
					printf("name: ");
					scanf("%s", name);
					printf("sno: ");
					scanf("%d", &sno);
					printf("age: ");
					scanf("%d", &age);

					new = new_node(name, sno, age);
					sort_insert(head, new);
					printf("当前链表为：\n");
					show_list(head);
					break;
			case 2:
					printf("\nplease input the sno of student:\n");
					scanf("%d", &sno);
					
					temp = find_stu(head, sno);
					if(temp == NULL)
					{
						printf("Not found！\n");
						continue;
					}

					printf("该学生信息为：\n");
					show_stu_single(temp);

					del = delete_stu(head, sno);
					free(del);
					del = NULL;
					printf("删除成功\n");
					printf("当前链表为：\n");
					show_list(head);
					break;
			case 3:
					show_list(head);
					break;
			case 4:
					printf("逆序输出：\n");
					reverse_stu(head);
					break;
			case 5: return 0;
		}
		
	}

	return 0;
}

//初始化链表
sList init_list()
{
	sList head = malloc(sizeof(stu));
	if(head != NULL)
	{
		INIT_LIST_HEAD(&(head->list));
	}

	return head;
}

//创建新节点
sList new_node(char *str, int sno, int age)
{
	sList new = malloc(sizeof(stu));
	if(new != NULL)
	{
		strcpy(new->name, str);
		new->sno = sno;
		new->age = age;
		// (&new->list)->next = (&new->list)->prev = NULL;
		new->list.next = new->list.prev = NULL;
	}
	return new;
}

//尾插入节点
void tail_insert(sList head, sList new)
{
	list_add_tail(&(new->list), &(head->list));
}

//按学号从小到大插入学生节点
int sort_insert(sList head, sList new)
{
	if(list_empty(&(head->list)))
	{
		printf("null\n");
		list_add_tail(&(new->list), &(head->list));
		return 0;
	}

	sList p, q;
	list_for_each_entry_safe(p, q, &(head->list), list)
	{
		if(p->sno > new->sno)
			break;	
	}
	list_add_tail(&(new->list), &(p->list));
	return 0;
}

//根据学号查找学生节点
sList find_stu(sList head, int sno)
{
	sList p, q;
	list_for_each_entry_safe(p, q, &(head->list), list)
	{
		if(p->sno == sno)
			return p;
	}
	return NULL;
}

//根据学号删除学生节点
sList delete_stu(sList head, int sno)
{

	sList p, q;
	list_for_each_entry_safe(p, q, &(head->list), list)
	{
		if(p->sno == sno)
		{
			list_del_init(&(p->list));
			return p;
		}		
	}

	return NULL;
}

//逆序打印链表
void reverse_stu(sList head)
{
	struct list_head *pos;
	sList p;
	list_for_each_prev(pos, &(head->list))
	{
		p = list_entry(pos, stu, list);
		printf("name:%s sno:%d age:%d\n", p->name, p->sno, p->age);
	}
}

//遍历单个学生节点
void show_stu_single(sList single)
{

	printf("name:%s, sno:%d, age:%d\n", single->name, single->sno, single->age);
}

//遍历
void show_list(sList head)
{
	sList p;
	struct list_head *q;

	list_for_each(q, &(head->list))
	{
		p = list_entry(q, stu, list);
		printf("name:%s sno:%d age:%d\n", p->name, p->sno, p->age);
	}
	printf("\n");
}


