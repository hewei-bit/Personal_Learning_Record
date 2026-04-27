#include "goods_manager.h"
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
void establish_warehouse()//建立库存
{
    FILE *fp = NULL;
    if((fp = fopen("goods.txt","w+"))== NULL)
    {
        printf("**************创建文件失败***************\n");
        return;
    }
    fprintf(fp,"001 苹果 10 0.2\n");
    fprintf(fp,"002 西瓜 20 0.3\n");
    fprintf(fp,"003 香蕉 30 0.4\n");
    fprintf(fp,"004 牛奶 40 0.5\n");
    fclose(fp);
    printf("成功导入信息\n");
    return;
}

/////////////////////////////////////////////////////////////////////////

int Manager_Login()
{
    char name[10];
    int secret[10];
    printf("      管理员登录    \n");
    printf("请输入管理员名：\n");
    scanf("%s",name);
    if(name == "1234")
    {

        printf("请输入密码：\n");
        scanf("%s",secret);
        if(secret == "1234")
        {
            printf("登陆成功\n");

        }
    }
}

int Manager_UI(int choice)
{
    printf("******************************************\n");
    printf("1.添加商品\n");
    printf("2.移除商品\n");
    printf("3.查找商品\n");
    printf("4.查看商品\n");
    printf("******************************************\n");
    printf("请选择你所需要的功能（请输入1-4）：\n");
    scanf("%d",&choice);
    return choice;
}


//初始化商品列表
PtrToGoods init_goods_list(void)
{
    PtrToGoods head = malloc(sizeof(struct goods));
    if (head == NULL)
    {
        printf("malloc list error\n");
        return NULL;
    }
    head->Next = NULL;
    return head;
}


//添加商品
/*
PtrToGoods addgood()//添加商品
{

}
*/
//移除商品
/*
_Bool deletegood()
{
    
} 
_Bool SearchGoods()
{
    
}
*/
void showGoods(PtrToGoods head)//查看商品
{
    FILE *fp;
    int i;
    if((fp = fopen("goods.txt","r+")) != NULL)
    {
	for (i = 0; i < 4;i++)
    	{
        	fscanf(fp,"%d %s %d %f",&head->code,head->goodsname,&head->prize,&head->discount);
		printf("%d %s %d %f",head->code,head->goodsname,head->prize,head->discount);     
		head = head->Next;
    	}
    }
    else
    {
        printf("打开文件失败！\n");
        return ;
    }
}
//
//
