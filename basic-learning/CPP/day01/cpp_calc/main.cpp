#include <iostream>

using namespace std;

int calculator(const int num1,char calc, const int num2)
{
    int result = 0;

    switch(calc)
    {
        case '+':
            result = num1+num2;

            break;
        case '-':
            result = num1-num2;

            break;
        case '/':
            if(num2 == 0)
            {
                cout << "除数不能为零！！！"<<endl;
                break;
            }
            result = num1/num2;

            break;
        case '*':
            result = num1*num2;

            break;
        default:
            cout << "输入异常"<< endl;
        break;

    }
    return result;
}

int main(void)
{
//    int i =100,j,k;
//    cout << "Hello World!" << endl;
//    cout << i << endl;
//    cout << "请输入 i>>>j>>k"<< endl;
//    cin >> i >> j >> k;
//    cout << "i = " <<i << "j = "<<j<<"k="<<k <<endl;

    int num1,num2;//变量
    char calc;//运算符
    int result;
    while(1)
    {
        cout << "请输入所需要计算的公式例如（1 + 2）,输入？退出" << endl;
        cin >> num1 >> calc >> num2;

        result = calculator(num1,calc,num2);
        cout << "result = "<< result <<endl;
    }



    return 0;
}
