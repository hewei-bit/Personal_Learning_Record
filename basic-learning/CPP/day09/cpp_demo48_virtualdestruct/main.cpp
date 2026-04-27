#include <iostream>
#include <cstring>

using namespace std;

class Shape //基类
{
  public:
    Shape()
    {
        cout << "Shape::Shape()" << endl;
    }
    virtual ~Shape()
    {
        cout << "Shape::destruct" <<endl;
    }
};

class Rect : public Shape
{

public:
    int w;
    int h;

    char* p;
     Rect()
     {
         cout << "Rect::Rect()" << endl;
         this->w = 10;
         this->h = 20;
         p = new char[20]; //申请堆内存
         strcpy(p,"hello");
     }
    ~Rect()
    {
        cout << "Rect::destruct" << endl;
        delete[] p; //释放内存
    }
};

int main()
{
    //Rect t;
    //对象创建在栈上，输出结果
    /*
Shape::Shape()
Rect::Rect()
Rect::destruct ----> 调用析构函数来进行释放资源
Shape::destruct
   */
    //利用指针赋值兼容原则
    Shape* p = new Rect(); //对象在堆上，堆内存需要程序员手动来进行释放

    delete p;
    /*
     * 析构函数为普通函数
Shape::Shape()
Rect::Rect()
Shape::destruct  --->只调用父类的析构函数，没有调用子类的析构函数，会造成内存泄露

     将基类的析构函数设置为虚函数,被称之为虚析构函数
Shape::Shape()
Rect::Rect()
Rect::destruct
Shape::destruct
    总结：在C++中，如果有继承，通常将基类的析构函数设置为虚析构函数，可以避免内存泄露
   */

    return 0;
}
