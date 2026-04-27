#include <iostream>

using namespace std;

class Test
{
public:
    Test(int tt = 0):t(tt)
    {
       cout << "  Test(int tt = 0) " << endl;
    }
    void printT()
    {
        cout << "t = " << t <<endl;
    }

    ~Test()
    {
        cout << "  ~Test() " << endl;
    }
private:
    int t;


};

void ctest()
{
    int i;
    int *p = (int*)malloc(sizeof(int));
    *p = 10;

    if(p != nullptr)
    {
        free(p);
        p = nullptr;
    }
}


int main()
{
   //回顾C语言使用堆内存使用方法
   ctest();
   //在C++中，一切都是面向对象，希望在对象被销毁时，可以自动去释放资源，释放资源可以由析构函数
   //来完成，关键谁来自动调用析构函数，对象在堆上时，只能开发者来 维护，对象在栈上，程序自己维护
   //在栈上实例化对象
 //  Test t(10);
  // t.printT();

   //在堆上实例化对象
    Test *p = (Test*)malloc(sizeof(Test));
    p->printT();

    if(p != nullptr)
    {
        //free(p);
        delete p; //malloc 和 delete可以相互匹配使用
        p = nullptr;
    }

    //综上可以看出，C++中，类类型在使用堆内存时，如果使用C语言的访问方式，创建对象，malloc --不会调用
    //构造函数，销毁对象时，free --->不会调用析构函数
    //在C++中，有了更好的解决办法new和delete运算符
    //语法：左边 类名* 指针变量 = new 类名(参数列表)
    //Test* t = new Test(10); //new 运算符创建堆对象时，会自动调用构造函数
   // t->printT();
   // delete t;  //delete 运算符会自动调用 析构函数；delete，只能释放一个对象，

    Test* tt = new Test[3];
    for (int i=0;i<3;i++) {
       tt[i].printT();

    }
    delete []tt;

    int *pp = new int[3];// ()
    for (int i=0;i<3;i++) {
        pp[i] = i; //
    }
   return 0;
}
