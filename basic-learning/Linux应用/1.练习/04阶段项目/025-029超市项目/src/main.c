#include "main.h"
#include "goods_manager.h"
#include "market_car.h"

////////////////////////////////////////////////////////////////////////////////////////
//主函数
int main()
{
    int main_choice;
    int manager_choice;
    int user_choice;
    PtrToGoods head;
    establish_warehouse();

    printf("请问你是管理员（1）还是用户（2）:\n");
    scanf("%d",&main_choice);
    if (main_choice == 1)
    {
        Manager_Login();
        head = init_goods_list(); 
        switch(Manager_UI(manager_choice))
        {
            case 1:break;
            case 2:break;
            case 3:break;
            case 4:showGoods(head); break;
            default: printf("输入的选项有误，请重新输入\n");
        }   
    }
    else if (main_choice == 2)
    {
        User_Login();       

        switch(User_UI(user_choice))
        {
            case 1:break;
            case 2:break;
            case 3:break;
            case 4:break;
            default: printf("输入的选项有误，请重新输入\n");
        }   
        
    }

}
