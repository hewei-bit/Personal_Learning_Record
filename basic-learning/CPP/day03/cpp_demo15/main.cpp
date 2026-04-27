#include <iostream>

using namespace std;

class Test
{
   public:
    Test()
    {
        a = 1;
        cout << "Test()" <<endl;
    }

    Test(int i)
    {
        a = i;
        cout << "Test(int i)" <<endl;
    }
    Test(int i,double d)
    {
        a = i;
        cout << "Test(int i,double d)" <<endl;
        cout << "a = " << a << "d = " <<d << endl;
    }

    Test(const Test& t)
    {
        a = t.a;
        cout << "Test(const Test& t)"<< endl;
    }

    void prinT()
    {
        cout << "a = " << a << endl;
    }
private:
    int a;
};
//全局函数
//类类型做为函数的形参 普通变量，另外，还有引用变量情况
void test(Test t)//Test t = t6
{
    cout << "test(Test t)" << endl;
}
//全局函数
//类类型做为函数的返回值 普通变量  引用变量
Test test2()
{
    Test tt; //调用Test()初始化
    cout << "Test test2()" << endl;
    return tt; //Test 匿名对象 = tt; //使用tt来初始化 匿名对象
}

int main()
{
//     Test t1; //调用Test()初始化
//    Test t2(2); //调用Test(int i)初始化
//    Test t3 = 3; //调用Test(int i)初始化 --->转换构造函数
//                    //当构造函数的参数只有一个时，并且参数是其它类型，该构造函数便称为转换构造函数
 //   Test t4(5,1.0); // Test(int i,double d)初始化
//    Test t5 = Test(3,4); //调用Test(int i,double d)
 //    Test t5 = t4;             //拷贝构造函数来初始化t5
 //   Test t6; //调用Test()初始化
 //   t6 = t5; //不是调用构造初始化，赋值操作 用一个对象给另一个对象赋值(=)
             //在C++对赋值运算符重新定义

    cout << "-----" << endl;
    //通过全局的域操作符调用全局函数
   // ::test(t6);


    cout << "------" << endl;
  //用函数test2的返回值来初始化t对象
  // Test t =  test2(); //要看具体的编译器来处理,用VS
    test2();

}
