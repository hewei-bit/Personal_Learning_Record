#ifndef __MARKET_CAR
#define __MARKET_CAR

#include "main.h"


/////////////////////////////////////////////////////////////////////
//函数声明
int User_UI(int choice);//主界面
void User_login();
//初始化购物车
PtrToGoods addToCar(MARKET_CAR M,PtrToGoods G);//将商品加入购物车
_Bool deleteFromCar(MARKET_CAR M,PtrToGoods G);//从购物车删除商品
void checkGoodsFromCar(MARKET_CAR M); //查看购物车商品价格、优惠及总价
void change_UserName();//修改用户密码    



#endif 
