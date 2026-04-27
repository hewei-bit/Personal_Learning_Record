#include "market_car.h"

//用户登录界面
void User_Login()
{

    printf("      管理员登录    \n");
    printf("请输入管理员名：\n");
    printf("请输入密码：\n");
}
int User_UI(int choice)
{
    system("clear");
    printf("1.将商品加入购物车\n");
    printf("2.将商品从购物车中删除\n");
    printf("3.查看商品总价\n");   

    printf("请选择你所需要的功能（请输入1-4）：\n");
    scanf("%d",&choice);
    return choice;


}


PtrToGoods addToCar(MARKET_CAR M,PtrToGoods G)//将商品加入购物车
{}
_Bool deleteFromCar(MARKET_CAR M,PtrToGoods G)//从购物车删除商品
{}
void checkGoodsFromCar(MARKET_CAR M)//查看购物车商品价格、优惠及总价
{

}


void change_UserName()//修改用户密码
{
    
}    
