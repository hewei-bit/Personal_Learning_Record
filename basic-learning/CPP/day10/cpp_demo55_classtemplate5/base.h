#ifndef BASE_H
#define BASE_H

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



#endif // BASE_H
