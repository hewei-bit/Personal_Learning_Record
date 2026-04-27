#include <iostream>

using namespace std;
//语法：
//返回值 operator 操作符(参数列表)
//{

//}
class A{
public:
    friend A operator+(A& a1,A& a2);
    A(int a = 0)
    {
        this->a = a;
    }
    //重载操作符 +

    //成员函数实现操作符重载
//    A operator+(A& a1)
//    {
//        //有了一个固定的对象 this
//        A temp;
//       temp.a =  this->a + a1.a ;
//       return temp;
//    }
    //以下写法错误
//    A operator+(A& a1,A& a2)
//    {

//    }
    int getA()const
    {
        return this->a;
    }

private:
    int a;
};

//全局操作符重载,对于双目操作符要传输两个操作数(参数)
A operator+(A& a1,A& a2)
{
    A temp;
   temp.a =  a2.a + a1.a ;
   return temp;
}
int main()
{
    int i,j;
    int k = i + j;

    A a1(1);
    A a2(2);
    A a3 = a1 + a2; //error 因为C++中，没有提供两个对象之间相加的功能，没有给操作符(+)实现两个对象相加
                      //想要进行两个对象可以相加，C++提供了操作符重载的方案
    cout << "a = " << a3.getA() << endl;
   // A a4 = a1.operator+(a2); //该函数的调用，等价于 表达式 a1 + a2
    return 0;
}
