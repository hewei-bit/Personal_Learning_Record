#include <iostream>

using namespace std;

class Test
{
public:
    Test(int tt)
    {
        t = tt;
        //使用一个合法的地址给 指针变量进行初始化
        p = (int*)malloc(sizeof(int));
        if(p == NULL)
        {
           cout << "malloc fail" << endl;
        }

        *p = tt;
        cout << "Test(int tt)" << endl;
    }

    //当类中的成员变量为指针类型,拷贝要使用深拷贝，不能使用浅拷贝
    Test(const Test& other)
    {
        t = other.t;

        p = (int*)malloc(sizeof(int));
        if(p == NULL)
        {
           cout << "malloc fail" << endl;
        }
        *p = *(other.p);

    }

    void printT()
    {
        cout << "t = " << t << "  " << "*p = " <<*p << endl;
    }

    void freeT()
    {
        if(p != nullptr)
        {
            free(p);
            p = nullptr;
        }
    }
private:
    int t;
    int* p; //当类中的成员变量为指针类型,拷贝要使用深拷贝，不能使用浅拷贝
    //当一个类成员变量为const

};
int main()
{
    Test t(10);
    t.printT();

    Test tt = t; //会调用默认的拷贝构造函数
    tt.printT();
    t.freeT();
    tt.freeT();

    return 0;
}
