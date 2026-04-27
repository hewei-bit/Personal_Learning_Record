#include <iostream>

using namespace std;
class Test
{
public:
    Test()
    {
        cout << "Test::Test()" <<endl;
    }
    Test(int t):t(t)
    {
        cout << "Test:: Test(int t)" <<endl;
    }
    ~Test()
    {
        cout <<"   ~Test()" << endl;
    }
    int t;
};

class Test1
{
public:
    Test1()
    {
        cout << "Test1::Test1()" <<endl;
    }
    Test1(int t1):t1(t1)
    {
        cout << "Test1:: Test1(int t1)" <<endl;
    }
    ~Test1()
    {
        cout <<"   ~Test1()" << endl;
    }
    int t1;
};
class Base
{
public:
    Base(){
        cout << " Base() " << endl;

    }
    Base(int b,int c):b(b),c(c)
    {
        cout << " Base(int b,int c):b(b),c(c) " << endl;
    }
    void printB()
    {
        cout << "Base::printB()" << endl;
        cout << this->b <<endl;
        cout << this->c << endl;
    }
    ~Base()
    {
        cout << "Base:: ~Base() " <<endl;
    }
    int b;
private:
    int c;
};
class Derive :public Base
{
  public:
    Derive(int d,int b,int c,int t,int t1):Base(b,c),d(d),t2(t1),t1(t) //子类中的构造函数函数会默认调用父类中的无参构造函数
    {
       // this->b = b; // ok 在子类中，直接初始化父类中的pulbic成员
        //this->c = 10; //error 在子类中，不能直接初始化父类中的private成员
                        //在子类中，不能直接调用构造函数，因为子类不能继承构造函数和
                        //析构函数，但是，可以通过构造函数初始化列表来显示调用父类中的
                        //构造函数

        cout << " Derive(int b):b(b) " << endl;
    }
    void printD()
    {
        cout << " Derive::printD()" << endl;
        this->printB();
    }
    ~Derive()
    {
        cout << "Derive::~Derive() "<<endl;
    }
    int d;
    Test t1; //在一个类中，包含一个无关自己类，称之为内嵌子对象t1,说明类与内嵌构成一个组合
             //在创建该类时，也要去实例化内嵌子对象t1,也会调用内嵌子对象类的构造函数
    Test1 t2; //内嵌子对象的构造函数的调用顺序跟内嵌子对象声明的顺序一致
};
int main()
{
    Derive d(1,2,3,4,5); //创建子类对象时，要先调用父类的构造函数，再调用子类的构造函数
                     //在子类对象被销毁时，先调用子类的析构造函数，再调用父类的析构函数
    d.printB(); //子类对象可以直接调用父类中的函数
    Base b;
    b = d; //子类对象直接赋值给父类对象
     Base bb = d;//子类对象直接初始化父类对象

     Base* bp = &d;
     bp->printB(); //父类指针可以直接指向子类对象
     //但是父类指针还只能调用父类中的成员
     bp->printB();
     Base& br = d; //父类引用可以直接引用子类对象

    return 0;
}
