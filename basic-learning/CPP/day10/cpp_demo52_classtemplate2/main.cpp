#include <iostream>

using namespace std;
/*
 类模板做为基类，并且派生类普通类
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

//派生类为普通类
//类模板做为基类而言，如果要使得派生类为普通类，那么在定义派生类时，要显示指定基类的泛型
class Derived : public Base<int>
{

};

class Derived1:public Base<string>
{
public:
    Derived1(int d, string id,string name):Base(name),d(d),id(id)
    {

    }

    void printD()
    {
        cout << " d = " << this->d << "id = " << this->id << "name = "<< this->b << endl;
    }
    virtual ~Derived1()
    {
        cout << "Derived1 :: destruct" << endl;
    }
private:
    int d;
    string id;

};

//定义一个学生类
class Student
{
private:
    int age;
    string sex;
};

//派生类为普通类，指定基类的泛型为类类型
class Derived2:public Base<Student>
{

};
int main()
{
     Derived1 d1(1,"123456","zhang3");
     d1.printD();
    return 0;
}
