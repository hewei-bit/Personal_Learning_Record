#include <iostream>

using namespace std;
//声明类成员函数做为友元函数步骤：
/*

第一步：哪一个类要声明其他类的成员函数做为友元函数，就将该类设置为前置声明
     比如：class A;
第二步：定义其他的类，比如类B
第三步：并且将其他类的成员函数在放在类外定义，类中声明
第四步：再将其他类的成员函数在本类中设置为友元函数
*/
class A;
class B //可以使用类来做为友元
{
public:
    friend class A; //将类声明为友元类
    B(int b = 0):b1(b)
    {

    }
    static void test(A a1); //可以使用该函数来做为友元


    void printB_A(A a1); //可以使用该函数来做为友元

private:
    int b1;
};

class A
{
   public:
    friend void printA(A a1); //声明全局函数做为友元
    friend void B::printB_A(A a1);
    friend void B::test(A a1); //将全局函数声明为友元
    A(int a=0,int b=0):a(a),b(b)
    {

    }
    int getA() const;
    void setA(int value);

    int getB() const;
    void setB(int value);
    void test(A a1)
    {
        B b;
        b.b1 = 0;
        cout << a1.a << " " << a1.b << endl;
    }
private:
    int a;
    int b;
};



//将全局函数声明为友元
void printA(A a1)
{
    //cout << a1.getA() << "   "<< a1.getB()<< endl;
   cout << a1.a << "  " << a1.b << endl;
}
int main()
{
   A a1(10,20);
   printA(a1);
   A a2;
   a2.test(a1); //a2.test(&a2,a1);
   B::test(a1); //如果该函数在程序中，频繁被调用，那么相当于a1.getA() 和 a1.getB()也被频繁调用
                //频繁在调用过程中，会大大增加的栈开销,所以在一些场合下，为了提高效率 ，而破坏类的封装性
               //引入友元
    return 0;
}

int A::getA() const
{
return a;
}

void A::setA(int value)
{
a = value;
}

int A::getB() const
{
return b;
}

void A::setB(int value)
{
b = value;
}

void B::test(A a1)
{
  cout << a1.a << "  " << a1.b << endl;
}

void B::printB_A(A a1)
{
    cout << a1.a << "  " << a1.b << endl;
}
