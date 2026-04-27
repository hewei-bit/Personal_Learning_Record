#include <iostream>

using namespace std;

class A{
public:

    A(int a = 0)
    {
        this->a = a;
    }
    int getA()const
    {
        return this->a;
    }

    //操作符重载 - *
    A operator -(const A& a1)
    {
       return A(this->a - a1.a);
    }

    A operator *(const A& a1)
    {
       return A(this->a * a1.a);
    }

private:
    int a;
};
//系统总共给我们提供了，默认的无参构造函数，默认的拷贝构造函数，默认的赋值操作符重载函数
//如果手动实现以上函数，系统提供的函数就不复存在
int main()
{
     A a1(2),a2(5);

     A a3 = a1 - a2; //等价于a1.operator-(a2);
    cout << a3.getA()<<endl;
    A a4 = a1 * a2;
    cout << a4.getA()<<endl;

    A a5;
    //a5.operator=(a4); 调用了系统默认提供的赋值操作符重载
      a5 = a4;
    return 0;
}
