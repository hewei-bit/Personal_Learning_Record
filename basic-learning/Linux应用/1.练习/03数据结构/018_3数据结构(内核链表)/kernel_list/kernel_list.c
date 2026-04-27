#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct one_kernel_list
{
    int num;
    char name[50];
    struct list_head my_list;
}list;
typedef struct one_kernel_list l_list,*LIST;

//初始化链表
LIST init_list(void)
{
    LIST head = (LIST)malloc(sizeof(list));
    if(head != NULL)
    {
        INIT_LIST_HEAD(&(head->my_list));
        return head;
    }
    return NULL;
}

//创建节点
LIST init_node(int num,char* name)
{
    LIST new = (LIST)malloc(sizeof(list));
    if(new != NULL)
    {
        new->num = num;
        strcpy(new->name,name);
        new->my_list.prev = NULL;
        new->my_list.prev = NULL;
        
        return new;
    }
    return NULL;
}

//插入节点

//遍历链表
void show(LIST head)
{
    LIST tmp;
    struct list_head *pos;

    list_for_each(pos,&(head->my_list))
    {
        tmp = list_entry(pos,l_list,my_list);
        printf("num:%d,name:%s\n",tmp->num,tmp->name);
    }
}

// 删除节点
void del_node(LIST head,int num,char* name)
{
    LIST tmp;
    struct list_head *pos,*n;
    list_for_each_safe(pos,n,&(head->my_list))
    {
        tmp = list_entry(pos,l_list,my_list);
        // printf("num:%d,name:%s \n",tmp->num,tmp->name);
        if(tmp->num == num && strcmp(tmp->name,name)==0)
        {
            list_del(pos);
        }
    }
}

int main()
{
    LIST head = init_list();
    LIST new = init_node(50,"abc");
    list_add(&(new->my_list),&(head->my_list));
    new = init_node(40,"666");
    list_add(&(new->my_list),&(head->my_list));
    new = init_node(30,"800");
    list_add_tail(&(new->my_list),&(head->my_list));

    show(head);

    putchar('\n');

    del_node(head,50,"abc");
    show(head);


}