#ifndef __MAIN_H
#define __MAIN_H          //条件编译，如果未定义次头文件名，则定义此文件名并执行下列语句
		                  //防止头文件重复包含
#include "account.h"				  
#include <stdio.h>
#include "list.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h> 

struct one_kernel_list;
int ac(struct one_kernel_list *head_staty,struct one_kernel_list *head_food,char *s);
int guest(struct one_kernel_list *head_food,struct one_kernel_list *head_staty,char *s);

double show_food(struct one_kernel_list *head);
double show_staty(struct one_kernel_list *head);

struct one_kernel_list *find(struct one_kernel_list *head, char *name);

struct one_kernel_list *init_list(void);

struct one_kernel_list *init_node(char *type,char *name,unsigned int count,float orprice,float cuprice,float discount);

struct one_kernel_list *del_node(struct one_kernel_list *head, char *name);

void show_r_add(struct one_kernel_list *head,char *s);           //以覆盖的的模式写入
void show_a_add(struct one_kernel_list *head,char *s);           //以追加的的模式写入,在文件尾写入

struct one_kernel_list *read_list(char *s,char *type);

void freesome(struct one_kernel_list *head);

void compare_guest(struct one_kernel_list *head_old,struct one_kernel_list *head_new,char *s);

#endif