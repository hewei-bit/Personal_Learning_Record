#include <iostream>

using namespace std;

//以前定义类
class A
{
int a;
};

//类模板:基本使用
template <class T,typename T2> //以template开头的类为类模板
class B
{
public:
    B(T b)
    {
        this->b = b;
    }
    void printB()
    {
        cout << "b = " << b <<endl;
    }
    T getB() const
    {
        return b;
    }
    void setB(const T &value)
    {
        b = value;
    }

private:
    T b;
};

int main()
{
    //main.cpp:27:5: error: use of class template 'B'
    //requires template arguments

    B<int,string> b1(10); //对于类模板而言，在具体使用时，必须显示指定泛型的类型T
    b1.printB();
    return 0;
}


