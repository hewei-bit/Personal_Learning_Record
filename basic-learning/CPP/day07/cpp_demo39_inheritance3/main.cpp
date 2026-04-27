#include <iostream>

using namespace std;

/*
 //在子类中，如果不实现拷贝构造函数,会调用父类的拷贝构造函数给父类的成员赋值
    //在子类中，一旦自实现拷贝构造函数，那么系统会自动调用
    //父类的普通无参构造，如果是这样的话，就失去了拷贝构造的意义了
    //所以要在子类实现拷贝构造函数时，显示调用父类拷贝构造函数

    //如果子类中未实现拷贝构造函数，那么会自调用到内嵌子对象拷贝构造函数
    //如果子类中自实现拷贝构造函数，那么系统会自动调用内嵌子对象的普通无参构造
    //如果是这样的话，就失去了拷贝构造的意义了，也要显示调用给内嵌子对象初始化

*/
class C
{
public:
    C()
    {
       cout << "C()" << endl;
    }
    //拷贝构造函数
    C(const C& another)
    {
        cout << "C(const C& another)" << endl;
    }
};

class A
{
public:
    A()
    {
         cout << "A()" << endl;
    }
    A(int a)
    {
       cout << "A(int a=0)" << endl;
       this->a = a;
    }
    A(const A& another)
    {
        cout << "A(const A& another)" << endl;
        this->a = another.a;
    }
    void printA()
    {
        cout << "a = " << this->a << endl;
    }
   private:
    int a;


};
class B : public A
{
 public:
    B(int a,int b):A(a)
    {

        this->b = b;
        cout << "B(int a,int b)" << endl;
    }
   //在子类中，如果不实现拷贝构造函数,会调用父类的拷贝构造函数给父类的成员赋值
    //在子类中，一旦自实现拷贝构造函数，那么系统会自动调用
    //父类的普通无参构造，如果是这样的话，就失去了拷贝构造的意义了
    //所以要在子类实现拷贝构造函数时，显示调用父类拷贝构造函数

    //如果子类中未实现拷贝构造函数，那么会自调用到内嵌子对象拷贝构造函数
    //如果子类中自实现拷贝构造函数，那么系统会自动调用内嵌子对象的普通无参构造
    //如果是这样的话，就失去了拷贝构造的意义了，也要显示调用给内嵌子对象初始化
//    B( const B& another):A(another),c(another.c)
//    {
//        cout << "B(const B& another)" << endl;
//        this->b = another.b;
//    }
    B(const B&another):A(another),c(another.c)
    {
        cout << "B(const B& another)" << endl;
        this->b = another.b;
    }
    void printB()
    {
        this->printA();
        cout << "b = " << this->b << endl;
    }

private:
    int b;
    C c; //内嵌子对象

};
int main()
{
    B b(10,20);
    b.printB();

    B bb(b); // B bb =b //两种写法都会调用 拷贝构造函数
    bb.printB();
    return 0;
}
