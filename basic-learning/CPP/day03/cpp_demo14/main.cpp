#include <iostream>

using namespace std;

//当一个类中，有多个构造函数时，1，多增加一个无参构造函数 ；2，可以使用默认参数来实现一
//对多的函数; 3,如果该类的类对象，只做其他类的类对象，不做单独创建对象时，不传参，在其
//他类实现构造函数时，可以使用构造函数初始化列表（构造函数初始化列表应用场景一）
class A
{
   public:
#if 0
    A(){}
    A(int a_a)
    {
        a = a_a;

    }
#else
    A(int a_a)
    {
        a = a_a;

    }
#endif
private:
    int a;
};

class Test{
public:
#if 1
    Test(int tt,A aa):a(aa)
    {
        t = tt;

    }
#else
    Test(int tt,A aa)
    {
        t = tt;

    }
#endif
private:

    int t;
    A a; //类类型对象
};
int main()
{
     //A a; //error 无法创建对象a
    return 0;
}
