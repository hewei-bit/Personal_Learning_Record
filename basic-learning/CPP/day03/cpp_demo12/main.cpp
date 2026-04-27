#include <iostream>

using namespace std;

class Person
{
public:
    //构造函数 -- 无参，如果有形参，形参都是成员变量，因为构造函数的主要工作是对成员变量进行初始化
#if 1
    Person()
    {
       cout << "Person() " << endl;
    }
    Person(const int a,const char s)
    {
        cout << "Person(const int a,const char s)" << endl;
        age = a;
        sex = s;
    }
#endif
    int getAge() const;
    void setAge(int value);

    char getSex() const;
    void setSex(char value);

private:
    int age;
    char sex;

};

//面试题：构造函数的作用
//1.构造函数用来初始化对象的成员的变量
//2.编译器在没有手动实现构造函数时，会提供一个无参构造函数，原因在于给创建对象时，提供一个上下文的环境

int main()
{
    //构造函数的调用 跟其他的成员函数调用方式不一样，在创建对象时，就由编译器直接传递参数并调用
    //Person p(20,'M'); //创建了一个Person的对象，然而，并没有给该对象 的成员变量age sex进行初始化

    //cout << p.getAge() << p.getSex() <<endl;
    //1、C++中，在创建对象时，就会自动调用构造函数,如果在类中没有实现对构造函数的定义，编译器会提供一个无参的构造函数
    //构造函数的函数体并且为空
    //2. 如果手动实现了构造函数，那么编译器不在提供构造函数
    Person p1;
    Person p(20,'M');
    return 0;
}

int Person::getAge() const
{
return age;
}

void Person::setAge(int value)
{
age = value;
}

char Person::getSex() const
{
return sex;
}

void Person::setSex(char value)
{
sex = value;
}
