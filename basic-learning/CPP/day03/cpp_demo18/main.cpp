#include <iostream>

using namespace std;

class  Test
{
 public:
    Test()
    {
         cout << "  Test()" << endl;
        p = (int*)malloc((sizeof(int)));
        if(p == nullptr)
        {
            cout << "malloc fail" << endl;
        }
        *p = 10;

    }
    void printT()
    {
        cout << "*p = " << *p << endl;
    }

    void freeP()
    {
        if(p != nullptr)
        {
            free(p);
            p = nullptr;
        }
    }
    //析构函数 :无参，不能构成函数重载
    ~Test()
    {
        cout << "  ~Test()" << endl;
        //释放资源
        if(p != nullptr)
        {
            free(p);
            p = nullptr;
        }
    }
private:
    int *p;
};


int main()
{

    Test t;
    t.printT();

    //t.freeP(); //虽然手动实现了对内存的释放，但是，释放内存的时间点，不好控制


    //希望在对象被销毁的时候，能够自动去释放内存,在C++中，有析构函数可以来实现，
    //在析构函数中，完成对资源的释放
    return 0;
}
