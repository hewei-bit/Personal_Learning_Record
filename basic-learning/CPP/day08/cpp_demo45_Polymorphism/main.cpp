#include <iostream>

using namespace std;


class C
{
public:
    C(){
       // cout << "C::C() " << endl;
    }

    virtual void eat()
    {
        cout << " C::eat()" <<endl;
    }
    ~C()
    {
        // cout << "C::~C() " << endl;
    }
   int c; //4

};

class D:public C //与继承的顺序有关
{
public:
    D(){
       // cout << "D::D() " << endl;
    }

    //虚函数重写，在父类中，虚函数要加上关键字 virtual，子类中可以加或者不加
   virtual void eat() //父类和子类必须要用同名的函数
    {
        cout << " D::eat()" <<endl;
    }

   int d; //4

   ~D()
   {
      //  cout << "D::~D() " << endl;
   }
};

void test(C* cc)
{
    cc->eat(); //对于这一个函数，不同对象来调用时，执行不同对象所对应的成员函数，这才是多态
              //cc ---> c  调用c类的eat函数  cc ---> d 调用D类的eat函数
}

void test1(C&cc)
{
    cc.eat();
}

int main()
{
//    D d;
//    d.eat(); //不同对象只是调用自己成员函数，不是多态
//    C c;
//    c.eat();//不同对象只是调用自己成员函数，不是多态

    D d;
    //test(&d);
    test1(d);
    C c;
    //test(&c);
    test1(c);
    return 0;
}
