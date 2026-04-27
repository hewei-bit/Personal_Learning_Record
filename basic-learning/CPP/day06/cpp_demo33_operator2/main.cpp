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

    //成员函数实现操作符重载
    const A operator+(const A& a1)
    {
        //有了一个固定的对象 this
        A temp;
       temp.a =  this->a + a1.a ;
       return temp;
    }
    //操作符重载函数的重载
    A operator + (int i)
    {
        return A(this->a + i);
    }
private:
    int a;
};

int main()
{
    int i =1;
    int j = 2;
    //(i+j) = 4; // error (i+j) 内置类型中，两个数相加这个表达式，不能做为左操作数

     A a1(1),a2(2);
     A a3 = a1 + a2;
     cout << a3.getA() << endl;
    // (a1+a2) = a3; //error 使用const 来限定修饰，两个对象相加，不能做为左操作数
    a3.operator+(1);

    cout << i << endl;
    cout << j << endl;

    //我们也希望能像上面输出i，j一样输出一个对象
    cout << a1 << endl;
    return 0;
}
