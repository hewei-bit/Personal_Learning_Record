#include <iostream>

using namespace std;

//将单例模式修改成类模板----可以应用任何类型的一对象
template <class T>
class SingleTon
{
public:
    //定义一个静态成员函数，该函数 的作用 是用来获取该类的一个对象
    static T* getInstance()
    {
            cout << "the object is created"<<endl;
            return instance;
    }
private:
    SingleTon() //手动实现无参的构造函数，将它设置为private
    {

    }
    //禁止类外尝试通过拷贝构造函数来创建对象
    SingleTon(const SingleTon& other) = delete ;

    //禁止类外尝试通过赋值运算符来给对象赋值，类似于int i = j;
    SingleTon& operator=(const SingleTon& other) = delete ;
    static T* instance;
};
template <class T>
T* SingleTon<T>::instance = new T;


class Teacher
{
public:
      friend class SingleTon<Teacher>; //声明Teacher友元为单例类模板
     void printT()
     {
         cout << this->name << endl;
         cout << "this = " << this << endl;
     }
     void setName(string name)
     {
         this->name = name;
     }
     string getName()const
     {
         return this->name;
     }
private:
     Teacher():name("zhang3")
     {

     }
    string name;
};

class Test
{
public:
    friend class SingleTon<Test>;
    void test()
    {
        cout << " test()" << endl;
    }
private:
    Test(){}
    Test(const Test& other) = delete ;
    Test& operator=(const Test& other) = delete ;
};
int main()
{

    Teacher* pt1 = SingleTon<Teacher>::getInstance(); //得到一个老师的对象
    Teacher* pt2 = SingleTon<Teacher>::getInstance();

     cout << pt1  << "   " << pt2 << endl;
     pt1->printT();
     pt2->printT();
     pt1->setName("li4");
     pt2->setName("wang5");

     pt1->printT();
     pt2->printT();

     Test* t = SingleTon<Test>::getInstance();
     t->test();
    // Test t; 不能直接实例化对象，只能通过单例设计模式来获取对象，保证唯一性
    return 0;
}
