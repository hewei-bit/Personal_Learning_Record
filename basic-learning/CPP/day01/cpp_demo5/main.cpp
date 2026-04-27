#include <iostream>

using namespace std;
/*
1.函数名必须相同 --- 前提条件
2.参数的类型不同 || 参数个数不同 || 参数顺序不同，均可构成重载
3.返回值类型不同则不可以做为函数重载依据
*/
int add(int a,int b)
{
    cout << "int add(int a,int b)"<<endl;
    return (a+b);
}
#if 0
//返回值类型不同不能构成函数重载的依据
char add(int a,int b)
{
    return (a+b);
}
#endif
//参数的类型不同

int add(char a,int b)
{
    cout << "int add(char a,int b)"<<endl;
    return (a+b);
}
//参数个数不同
int add(int a,int b,int* result)
{

    cout << "int add(int a,int b,int* result)"<<endl;
    return 0;
}
//参数顺序不同
int add(int* result,int a,int b)
{

    cout << "int add(int* result,int a,int b)"<<endl;
    return 0;
}
int main()
{

    int a =5;
    int b = 3;
    char c = 'c';
    char d = 'd';

   add(c,a);
   add(c,d);
    return 0;
}
