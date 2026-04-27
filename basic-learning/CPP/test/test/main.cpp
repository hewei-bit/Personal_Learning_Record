#include <iostream>

using namespace std;

class A
{
public:
    A() {}
    int a;
};
class B
{
public:
    B() {}
    int c;
    void fun0(){}
};

class C
{
public:
    C() {}
    char c1;
    char c2;
    virtual void fun1(){}
    virtual void fun2(){}
};
class D:public A,public C
{
public:
    D() {}
    int d;
    virtual void fun1(){}
    virtual void fun2(){}
};

class E:virtual public B,virtual public C
{
public:
    E() {}
    int e;
    virtual void fun3(){}
    virtual void fun2(){}
};
int main()
{
    cout << "Hello World!" << endl;
    A a;
    B b;
    C c;
    D d;
    E e;
    cout << "a " <<sizeof(a)<<endl;
    cout << "b " <<sizeof(b)<<endl;
    cout << "c " <<sizeof(c)<<endl;
    cout << "d " <<sizeof(d)<<endl;
    cout << "e " <<sizeof(e)<<endl;
    return 0;
}

