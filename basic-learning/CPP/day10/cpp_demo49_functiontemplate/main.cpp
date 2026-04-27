#include <iostream>

using namespace std;

//以前定义函数
void func2(int a,int b)
{
  cout << "func1::" << a << b << endl;
}
//如果定义函数模板
template <class T> //编译器编译到template时，它就知道这是一个模板，然后不进行了
void func2(T a,T b)
{
    cout << a << "  " <<b <<endl;
}
template <typename T>
void func2(T a) //函数模板也可以函数重载
{
 cout << a << endl;
}
template <class A,typename T>  //每一个泛型只能对当前这个函数来有效
void func3(A f,T t)
{
    cout << f << "  " << t << endl;
}

int main()
{
   func2(3,4); //如果是函数模板时，在调用的时候，可以通过参数值类型隐式推导T的类型

   func2(1.0,2.5);
   func2<int>(6,4); //显示指定T的类型

   func3(2,'c');
    return 0;
}
