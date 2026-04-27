#include "base.h"
#if 1
//以下的函数模板，编译器在第一次编译时，Base(const T1& name,const T2& age )
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
#endif
