#ifndef MARKET_H
#define MARKET_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////
typedef struct goods *PtrToGoods;//商品属性
struct goods{
    int code;//商品编号
    int prize;//商品价格
    float discount;//商品折扣
    char goodsname[20];//商品名
    PtrToGoods Next;
};
typedef PtrToGoods Position;
typedef PtrToGoods List;

//购物车声明
struct market_car
{
    PtrToGoods buy;//货物列表
    int number;//购物数量
    struct market_car *next;
};
typedef struct market_car * MARKET_CAR;
typedef MARKET_CAR FIRST_CAR;

//用户声明
typedef struct user *PtrToUsers;
struct user{
    char username[20];
    int usercode;  
    PtrToUsers Next;
};
//管理员声明
typedef struct Manager *PtrToManagers;
struct Manager
{
    char Managername[20];
    int Managercode;  
    PtrToManagers Next;
};




#endif
