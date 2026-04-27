#include <iostream>

using namespace std;

class Test{

public:

    Test(int ii=0,const int aa=0,const int bb = 0):a(aa),i(ii),b(bb)
    {


    }

    void printT()
    {
        cout << "i = " << i <<"  " << "a = " << a  << "b = " << b << endl;
    }
    int getI() const;
    void setI(int value);

private:
    int i; //普通的类成员变量
    const int a;
    const int b = 10;
    //不推荐使用
    //const int a = 10; //在c++中，const int a是一个常量，在声明的时候，就要进行初始化
};
int main()
{
    //在类实例化对象时候，要分配内存空间

    Test t(1,2);
    t.printT();
    Test t1(1,3);
    t1.printT();

   const Test t2; //const 类对象，只能调用const成员函数，不能调用非const成员函数



    return 0;
}

int Test::getI() const
{
return i;
}

void Test::setI(int value)
{
i = value;
}
