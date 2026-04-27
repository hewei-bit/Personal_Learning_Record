#include <stdio.h>
#include <stdlib.h>

#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"



//设计节点
typedef struct node
{
    int data;
    struct node *next;
}listnode,*single_list;


//新链表初始化
struct node* init_list(void)
{
    struct node *head = malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("malloc list err\n");
        return NULL;
    }
    head->next = NULL;
    return head;
}

//创建新节点
 struct node * new_node(int data)
 {
    single_list new = malloc(sizeof(listnode));
    if(new == NULL)
    {
        printf("malloc new err \n");
        return NULL;
    }
    new->next = NULL;
    new->data = data;
 }
//将新节点插入到链表尾
int tail_insert(single_list head,single_list new)
{
    
    single_list p = head;
    //让p指针指向最后一个节点
    while(p->next)
        p = p->next;
    //新节点插入队尾
    p->next = new;
    return 0;
}
//将新节点插入到链表头
int head_insert(single_list head,single_list new)
{
    single_list p = head;
    new->next = p->next;
    p->next = new;
    return 0;    
}
//查找节点，通过节点数据
single_list search_node(single_list head,int data)
{
   single_list p = head;
   p = p->next;
   while(p)
   {
       if(data == p->data)
            break;
        p = p->next;
   }
   return p;
}
//指定位置插入，将新节点插入到指定位置之后
int insert_node(single_list head,int data,single_list new)
{
    single_list p = search_node(head,data);
    if(p == NULL)
        return -1;

    new->next = p->next;
    p->next = new;
    return 0;
}


//删除指定节点
single_list del_node(single_list head,int data)
{
    single_list p = search_node(head,data);
    if(NULL == p)
        return NULL;
    
    while(head->next != p)
        head = head->next;
    
    head->next = p->next;
    p->next = NULL;
    return p;
}

/* 移动节点，将数据为src的节点移动到数据为dest的节点之后 */
int mv_node(single_list head,int src,int dest)
{
    /* 将数据为src的节点从链表中拿出来 */
    single_list p = del_node(head,src);
    if(NULL == p)
    {
        printf("not found \n");
        return -1;
    }

    /* 将src的节点插入到数据为dest的节点之后*/
    int ret = insert_node(head,dest,p);
    if(-1 == ret)
    {
        printf("insert fail \n");
        return -2;
    }
    return 0;
}

//链表遍历
void show(struct node *head )
{ 
    int count = 1;
    single_list p = head;
    p = p->next;
    while (p)
    {
        printf(YELLOW"NO. %d,data: %d \n",count,p->data);
        p = p->next;
        count++;
    }
}

int main()
{
    single_list head = init_list();

    single_list new_1 = new_node(3);
    if(NULL == new_1)
    {
        printf("new node err \n");
        return -1;
    }

    single_list new_2 = new_node(4);
    if(NULL == new_1)
    {
        printf("new2 node err \n");
        return -2;
    }

    single_list new_3 = new_node(5);
    if(NULL == new_3)
    {
        printf("new3 node err \n");
        return -3;
    }

    int ret = tail_insert(head,new_1);
    if(ret == 0)
        new_1 = NULL;

    ret = tail_insert(head,new_2);
    if(ret == 0)
        new_2 = NULL;


    
    ret = insert_node(head,3,new_3);
    if(ret == 0)
        new_3 = NULL;



    show(head);

    /*
    printf("请输入一个你要搜索的值：\n");
    int num;
    scanf("%d",&num);

    single_list search =  search_node(head ,num);
    printf("你要搜索的节点为：%d \n",search->data);
    */
    putchar('\n');
   mv_node(head,5,4);

    show(head);

    del_node(head,3);
    show(head);

    return 0;
}








