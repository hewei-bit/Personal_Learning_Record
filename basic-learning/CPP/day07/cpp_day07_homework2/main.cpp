#include <iostream>
#include "myclock.h"
#include "unistd.h"

using namespace std;

//前置、后置自增运算符、输出格式控制
//定义一个秒表MyClock类，包含数据成员是分和秒，模拟秒表，
//每次走一秒，满六十秒就进一分钟。输出分秒的值。
//要实现 ++ ，--的运算符重载

int main()
{
//    cout << "Hello World!" << endl;

    int num = 0,h,m,s;
    cout << "set hour:"<<endl;
    cin >> h;
    cout << "set minute:"<<endl;
    cin >> m;
    cout << "set second:"<<endl;
    cin >> s;
    Myclock cc(h,m,s);
    while(1)
    {
        cout << "please input 0 or 1"<<endl;
        cout << "tips:0 is a forward count,1 is the reverse order count"<<endl;
        cin >> num;
        switch (num) {
            case 0:
                count(cc);
            break;
            case 1:
                countReverse(cc);
            break;
            default:
                break;
        }
    }

    return 0;
}
