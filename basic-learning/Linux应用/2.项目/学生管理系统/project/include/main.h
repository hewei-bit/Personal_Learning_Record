#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//学生节点
typedef struct _STU
{
    char arrStuNum[10];
    char arrStuName[10];
    int iStuScore;
    struct _STU* pNext;
}STUNODE;

//打印
void showData();
//指令界面
void UI();


//添加一个学生的信息(尾插)
void AddStuMSG(char *arrStuNum,char arrStuName[10],int iStuScore);
//链表头部添加一个节点(头插)
void AddStuMSGToLinkHead(char *arrStuNum,char arrStuName[10],int iStuScore);
//清空链表
void FreeLinkData();
//按学号查询
STUNODE* FindStuByNum(char *arrStuNum);
//指定位置插入
void InsertNode(STUNODE* pTemp,char *arrStuNum,char arrStuName[10],int iStuScore);
//删除指定学生的信息(姓名/学号)
void DeleteStuNode(STUNODE* pNode);


//保存学生的信息到文件中
void SaveStuToFile();
//读取文件中学生的信息
void ReadstuFromFile();


#endif // !__MAIN_H

