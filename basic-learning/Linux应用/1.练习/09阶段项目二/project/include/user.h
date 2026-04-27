#ifndef _USER_H
#define _USER_H
#include "main.h"


USER init_user_list();//初始化链表
USER new_user_node(char *username, char * password);//创建新节点
void tail_insert_user(USER head, USER new);//尾插入节点

USER find_user(USER head, char *username);//根据用户名查找用户
USER delete_user(USER head, char *username);//根据用户名删除用户节点
void show_user_single(USER single);//遍历单个用户节点
void show_user(USER head);//遍历
void reverse_user(USER head);//逆序打印链表


#endif

