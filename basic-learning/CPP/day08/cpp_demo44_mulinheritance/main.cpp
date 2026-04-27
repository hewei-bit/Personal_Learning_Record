#include <iostream>

using namespace std;
//普通继承：菱形问题
class A
{
   public:
    A(){
        cout << "A::A() " << endl;
    }
    virtual void testA()
    {

    }
    ~A()
    {
         cout << "  A::~A() " << endl;
    }
    int a; //4

};
class B:virtual public A
{
public:
    B(){
        cout << "B::B() " << endl;
    }
    ~B()
    {
         cout << "B::~B() " << endl;
    }
   int b; //4

};

class C :virtual public A
{
public:
    C(){
        cout << "C::C() " << endl;
    }
    virtual void test()
    {

    }
    ~C()
    {
         cout << "C::~C() " << endl;
    }
   int c; //4

};

class D:public C,public B //与继承的顺序有关
{
public:
    D(){
        cout << "D::D() " << endl;
    }
   int d; //4

   ~D()
   {
        cout << "D::~D() " << endl;
   }
};

//单继承：构造：先父类，内嵌对象，再子类
//   普通的多继承： 构造：祖父类 ----> 父类一 --->祖父类 ----> 父类二 ---> 子类
//                析构：与构造的顺序相反

// 虚继承的多继承：构造：祖父类 ----> 父类一  ----> 父类二 ---> 子类
     //  析构：与构造的顺序相反
/*
虚继承的总结：
        1，所占内存空间会更大
        2，虚继承的底层实现原理：由编译去维护vptr + vptable
        ,当要调用虚函数时，首先要通过vptr移动去查表，找到之后，再调用虚函数
        ，比调用普通函数要低（普通函数不要查表，直接调用）
        3，对于公共的成员，只保留一份在祖父类中，父类和派生类在使用的时候，只是对在祖父类
        中成员进行了一次拷贝，他们修改的只是拷贝过来的副本的值
*/
int main()
{
    D d;
    cout << sizeof(D) << "   " << sizeof(d) << endl; //20  多继承会造成存储空间会变大
                                                     // 24  虚继承更加会造成存储空间会变大
    d.a = 20;
    return 0;
}
