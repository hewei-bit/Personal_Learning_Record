#include <iostream>

using namespace std;


void printT(int a)
{

    cout << "a = " << a << endl;
}
//默认参数的顺序：从最右边开始设置，左边参数想要设置为默认参数，那么它的右边参数必须为默认参数
//对于默认参数而言，函数调用时，不传入参数值，则使用参数的默认值 ，如果重新传入了参数值，则使用
//新的参数值
int calc(int width,int length,int heigh=80)
{
    cout << " calc = " << heigh * width * length << endl;
}
#if 0
//有默认参数的函数，不能实现函数重载，也不要进行函数重载来设置
int calc(int width,int length)
{

}
#endif

int test(int t,int) //占位参数
{

}

int main()
{
    printT(10);

    //A公司
    calc(5,8);

    //B公司
     calc(7,10);

     //如果在实际应用中，某一个参数通常情况下，不变，除非定制需求，该参数可以考虑使用默认参数
     calc(100,100,100);

     test(10,20); //对于占位参数而言，在传入参数时，一定要传入一个值，不能像默认参数那样，可以省略
    return 0;
}
