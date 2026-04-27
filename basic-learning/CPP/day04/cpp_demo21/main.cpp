#include <iostream>

using namespace std;

class Test
{
public:
    Test(int t,int i):t(t),i(i)
    {
       this->t = t;
       // this->i = i; const 成员变量，不能这样直接初始化
    }

    //非const成员函数
    void printT()
    {
       this->t = 20;
        cout << this->t << "  " << this->i<<endl;
        this->getData(); //ok 非const成员函数可以调用const成员函数
    }

    //const成员函数
    int getData()const
    {
        //const 成员函数,承诺本函数不会修改类内的数据成员,且不会调用其它非const成员函数
        //this->t = 20; error 非const成员变量

        return t;

    }

    void test()const
    {
        this->getData(); //okconst成员函数可以调用const成员函数
    }
public:
    //成员变量：普通的内置类型，类类型，const
    int t;
    const int i;
};
int main()
{
     Test t1(10,20);
     t1.printT();

     const Test t2(30,40);
    // t2.t = 50; //error const 对象不能访问非const成员变量
    // t2.i = 100; // error const 对象不能修改const 成员变量
     cout << t2.i << endl; //const 对象只能调用const成员函数和读取const成员变量值
    return 0;
}
