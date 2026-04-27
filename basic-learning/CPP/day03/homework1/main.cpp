#include <iostream>

using namespace std;

class Test
{
public://成员函数
    //无参构造函数
    Test(){}
    //有参构造函数
    Test(int a,int b)
    {
        m_a = a;
        m_b = b;
    }
    //拷贝构造函数
    Test(const Test &t)
    {
        cout <<"拷贝构造函数被执行"<<endl;
    }
    //析构函数
    ~Test()
    {
        cout <<"析构函数被执行"<<endl;
    }

private://成员变量
    int m_a;
    int m_b;
};

Test gg()
{
    cout << "gg() begin..." << endl;
    Test temp(100, 200); //局部变量
    cout << "gg() before return temp" << endl;
    return temp;
}

void test1()
{
    cout << "test1 begin ..." << endl;
    Test t1 = gg();
    cout << "test1 end..." << endl;
}

int main()
{
//    Test t1,t2;
       test1();
       gg();

    return 0;
}
