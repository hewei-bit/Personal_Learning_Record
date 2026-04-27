#include <iostream>

using namespace std;

//定义的语法
//成员变量名类型 类名::*指针名 = & 类名::成员变量名
//使用方法：
//对象名.*指针名
//对象指针名->*指针名

//定义语法
//返回值 (类::*函数指针变量名)(形参列表) = &类::类成员函数名；
//在C++中，指向类成员的指针，也必须通过对象来调用它
//使用方法：
//(对象名.*函数指针变量名)(参数)
//(对象名->*函数指针变量名)(参数)

class A
{
public:
     void func(int f) //成员函数
     {
         cout << "f = " << f << endl;
     }
public:
    int a;
    int b;
};

int main()
{
    // c int --- int*  int*p = &a;
    //在C++中，所以的变量都是归属  局部变量  全局变量  类成员变量
    //定义一个指针指向成员变量
    int A::*pa =  &A::a; //从类的层面来看，类就相当于一个命名空间，a的就是类A中变量

    A a1; //对象创建在栈上
    cout << "a = " << a1.a << endl;
    a1.*pa = 10;

    cout << "a = " << a1.a << endl;

    A *a2 = new A; //对象创建在堆上
    a2->*pa = 20;

    cout << "a = " << a2->a << endl;
    delete  a2;
    //定义一个指针指向成员函数
    void (A::*funcp)(int f) = &A::func;

    //通过对象来使用指针
    A a3;
    (a3.*funcp)(10);

    A* a4 = new A;
    (a4->*funcp)(20);
    delete  a4;
    return 0;
}
