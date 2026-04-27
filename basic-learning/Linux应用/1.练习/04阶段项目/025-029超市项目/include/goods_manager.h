#ifndef __MANAGER_H
#define __MANAGER_H

#include "main.h"

void establish_warehouse();//简历库存
int Manager_Login();//管理员登录
int Manager_UI();//管理员界面
PtrToGoods addgood();//添加商品
_Bool deletegood(); //移除商品
_Bool SearchGoods(); //查找商品
void showGoods(PtrToGoods head); //查看商品

PtrToGoods init_goods_list(void);//初始化商品列表
#endif
