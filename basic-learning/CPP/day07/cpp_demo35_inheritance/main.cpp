#include <iostream>

using namespace std;

class Test{
private:
    int t;
};
class Test1{
private:
    int t;
};

class Person{

  public:
    void test(Test t) //use-a
    {

    }
private:
    Test t1;
    Test1 t2; //has - a
};

class scientists{

};
//is-a  Student -- 派生类(子类) Person--基类（父类）
class Student:public Person //单继承  public private protected代表着继承方式
{
public:
    void test()
    {
        this->pub = 10; //在类中可以访问
        this->pri = 20;
        this->pro = 20;
    }
    void test2();
public://它修饰的成员的作用域限定在本类中和类外都可以访问
    int pub;
protected:
    int pro; //它修饰的成员的作用域限定在本类中，
             //除此之外 ，不可见,另外，在继承中，对子类是可见,如果只是在一个类中
             //跟private是一样
private: //它修饰的成员的作用域限定在本类中，除此之外 ，不可见
    int pri;
};

void Student::test2()
{
    this->pub = 20; //成员函数不管在类中实现和类外实现，都的作用域都称之为类中
    this->pri = 20;
    this->pro = 20;
}
//子类中对父类中的东西访问的权限跟继承方式
class Collegestudent:public Student,public scientists //多继承
{
public:
    void printC()
    {
       pub = 40;
       pro = 40;  //问题：父类中的protect修饰的成员，在子类中可见，在类外不可见
                      //只能说明该成员有可能仍然是protect，或者private
                      //要看孙子类可见来判断
      // pri = 40; //error 因为在父类中由private，所以在子类中不可见
    }
private:
    string name;
};

//孙子类
class  CollegestudentChile:public Collegestudent
{
    void printCC()
    {
       // pro = 30; //在孙子类中，pro是可见性，说明父类中pro成员，在子类中为protectd
    }
};
//以上是说明private protected public三个修饰成员时，他们的可见性区别

//接下来，讨论父类中的成员被继承到子类中后，他们的可见性跟继承的方式有关联
// 公有继承(public)
//父类中public成员,在子类中，可见性仍然属于public成员
//父类中protected成员，在子类中，可见性仍然属于protected成员
//父类中private成员，在子类中，不可见
int main()
{
    //父类对象
  Student s1;
  s1.pub = 30; //类外可以使用public修饰的成员
 // s1.pri = 30; // error private修饰的成员，在类外不可见
//  s1.pro = 30; // error protected修饰的成员，在类外不可见

  //子类对象
  Collegestudent c1;
  c1.pub = 30;
 // c1.pro = 30; 父类中的protect成员，子类对象在类外不可见
 // c1.pri = 30; 父类中的private成员，子类对象在类外不可见
    return 0;
}
