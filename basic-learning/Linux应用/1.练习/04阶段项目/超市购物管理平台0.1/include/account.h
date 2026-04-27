#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "list.h"

#define SIZE 6
#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"	
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"
 
#define BOLD                 "\e[1m"					//设置高亮度
#define UNDERLINE            "\e[4m"					//下划线
#define REVERSE              "\e[7m"					//反显 
#define HIDE                 "\e[8m"					//消隐
#define CLEAR                "\e[2J"					//清屏

#include "main.h"




typedef struct The_users   //typedef 可以定义结构体别名
{
    char id[SIZE]; //账号 
    char pwd[SIZE]; //密码 
	char phone[SIZE]; //电话号码为长整型 用做找回密码
}users;

typedef struct The_admins   //typedef 可以定义结构体别名
{
    char id[SIZE]; //账号 
    char pwd[SIZE]; //密码 
	char phone[SIZE]; //电话号码为长整型 ,实际写入的字节是多少呢？如果在改动对的话会不会覆盖其它数据
}admins;                                //栈中,其实也可以共用同一个结构体

struct one_kernel_list       //结构体
{   
    char type[20];                          //商品类型 
   	char name[20];
	unsigned int  count;         //库存
	float orprice;
	float cuprice;
	float discount;
	struct list_head my_list;
};


// extern admins a,b; //b 管理员txt账户存储
// extern users  d,c; //c 用户txt账户存储

#endif