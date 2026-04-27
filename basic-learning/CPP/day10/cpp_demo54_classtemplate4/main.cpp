#include <iostream>

using namespace std;

//类模板的成员函数和类模板在同一个文件中
template <class T1,class T2>
class Base //Base<T1,T2>
{
public:
    Base(const T1& name=0,const T2& age = 0);

    virtual ~Base();

    T1 getName() const;
    void setName(const T1 &value);

    void printB();

protected:
    T1 name;
    T2 age;
};

template <class T1,class T2>
Base<T1,T2>::Base(const T1& name,const T2& age )  //如果函数在声明的时候，使用了默认参数，
{                                                //定义的时候，就不要再使用默认参数

    this->age = age;
    this->name = name;
}

template <class T1,class T2>
Base<T1,T2>::~Base()
{
    cout << "Base<T1,T2>::destruct" << endl;
}

template <class T1,class T2>
T1 Base<T1,T2>::getName() const
{
    return name;
}

template <class T1,class T2>
void Base<T1,T2>::setName(const T1 &value)
{
    name = value;
}

template <class T1,class T2>
void Base<T1,T2>::printB()
{
    cout << "name = " << this->name << "age = " << this->age << endl;
}


int main()
{
    Base<string,int> b("li4",20);
    b.printB();
    return 0;
}
