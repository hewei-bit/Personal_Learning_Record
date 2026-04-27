#ifndef __CLIENT_H
#define __CLIENT_H

#include "main.h"


CLIENT init_client_list();//初始化链表
CLIENT new_client_node(	char ip[30],unsigned short port,int accept_fd);//创建新节点
void tail_insert_client(CLIENT head, CLIENT new);//尾插入节点

CLIENT find_client(CLIENT head, unsigned short port);//根据用户名查找用户
CLIENT delete_client(CLIENT head, unsigned short port);//根据用户名删除用户节点
void show_client_single(CLIENT single);//遍历单个用户节点
void show_client(CLIENT head);//遍历
void reverse_client(CLIENT head);//逆序打印链表
void show_client_to_client(CLIENT head,int accept_fd);

#endif