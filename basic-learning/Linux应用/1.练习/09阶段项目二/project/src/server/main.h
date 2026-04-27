#ifndef __MAIN_H
#define __MAIN_H

#include "head.h"

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
#define CLEAR                "\e[2J"					//清

//定义用户节点
struct user
{
	char username[30];
	char password[30];
	struct list_head list;//内核链表小结构体
};//分号
typedef struct user User,*USER;

//定义客户节点
struct client
{
	char username[30];
	char ip[30];
	unsigned short port;
	int accept_fd;
	struct list_head list;//内核链表小结构体
};//分号
typedef struct client Client,*CLIENT;




#endif