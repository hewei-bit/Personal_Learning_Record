#include <iostream>
#include "goods.h"
using namespace std;

//经销一种商品，商品进货和售出时以箱为单位，
//各箱质量不一样

int main()
{
    cout << "Hello World!" << endl;
    Goods apple;
    GOODS head = &apple;
    int num =0 ;
    while(1)
    {
//        system("cls");
        cout << "1.加货" <<endl;
        cout << "2.出货" <<endl;
        cout << "3.退出" <<endl;
        cin >> num;
        switch (num)
        {
            case 1:
                buy(head,50);
                cout <<"total_weight" <<head->getTotalWeight()<<endl;
                break;
            case 2:
                sale(head);
                cout <<"total_weight" <<head->getTotalWeight()<<endl;
                break;
            case 3:
                return 0;
            default:
                cout << "输出有误请重新输入"<<endl;
                break;
        }
    }



}



