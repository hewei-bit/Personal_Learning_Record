#include <iostream>

using namespace std;
/*
 类模板做为基类，并且派生类仍然为类模板
*/

template <class T>
class Base{  //看到的类名为Base，实际上类名为Base<T>
public:
//    Base(){}
    Base(const T& b = 0)
    {
        this->b = b;
    }
    virtual ~Base()
    {
        cout << "Base :: destruct" << endl;
    }
protected:
    T b;
};
//类模板做为基类，派生类在定义时，有两种选择，一种显示指定基类的泛型，另一种继续使用泛型
//派生类仍然为类模板
template <class T,class T1> //派生类中可以继续增加新的泛型，当然，也可以不增加
class Derived : public Base<T> //Derived<T,T1>
{
public:
    Derived(T age,T1 name,T b):Base<T>(b) //在派生类的类模板中，使用构造函数初始化列表时，
    {                                    //调用基类的构造函数时要使用基类名<T>
        this->age = age;
        this->name = name;
    }
private:
    T age;
    T1 name;
};

int main()
{
    Derived<int,string> d(19,"li4",20); //派生的类模板在实例化对象时，要显示指定基类的泛型和派生类的泛型
    return 0;
}
