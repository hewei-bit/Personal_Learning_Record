#include <iostream>

using namespace std;
class A
{
   public:
    A()
    {
       pfunc[0] = &A::methodA;
       pfunc[1] = &A::methodB;
       pfunc[2] = &A::methodC;
       pfunc[3] = &A::methodD;
       //cout << "A()" << endl;
    }
    //提供给客户的接口
    //参数一：val 传递给函数的值，type 选择哪一种方法
    void select(int val,int type) //类成员函数中包含了this
    {
       //cout << type << endl;
          if(type < 0 || type > 3) //防止数组越界
          {

                 return;
          }
          (this->*pfunc[type])(val);
    }
 private:
    void methodA(int a)
    {
           cout << "methodA = " << a << endl;
    }

    void methodB(int b)
    {
          cout << "methodB = " << b << endl;
    }

    void methodC(int c)
    {
          cout << "methodC = " << c << endl;
    }

    void methodD(int d)
    {
          cout << "methodD = " << d << endl;
    }

    //定义一个指向类成员函数指针
    void (A::*pfunc[4])(int a);
};

int main()
{

    A a1;
    a1.select(10,0); //调用了类中A方法

    a1.select(100,2); //调用了类中C方法
    return 0;
}
