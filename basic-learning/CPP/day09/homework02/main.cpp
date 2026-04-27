#include <iostream>

using namespace std;

//设计一个基类Shape包含成员函数Show(), 将Show()声明为纯虚函数。
//Shape类公有派生矩形类Square（正方形）和圆类Circle（圆形），
// 功能1： 分别定义Show()实现其主要集合元素的显示。使用抽象类Shape
//类型的指针，当它指向某个派生类的对象时，就可以通过访问该对象的虚函数
//成员Show()。
// 功能2：用ShowArea()分别显示各种图形的面积.最后还要显示所有图形
//的各个面积。要求使用指针数组，数组的每个元素指向一个派生类对象。
class Shape
{
public:
    Shape()
    {
        cout << "Shape()" << endl;
    }
    virtual ~Shape()
    {
        cout << "~Shape()" << endl;
    }

    virtual void show() = 0;
    virtual void showArea() = 0;

};

class Square:public Shape
{
public:
//    Square() {
//        cout << "Square()" << endl;
//    }
    Square(int length = 5) :length(length){}
    void show()
    {
        cout << "length : "<< this->length<<endl;
    }
    void showArea()
    {
        int area = this->length * this->length;
        cout << "the ares of Square : "<<area<<endl;
    }
    virtual ~Square()
    {
        cout << "~Square()" << endl;
    }

    virtual void setLength(int value);

    int getLength() const;

private:
    int length;

};

class Circle:public Shape
{
public:
//    Circle() {
//        cout << "Circle()" << endl;
//    }
    Circle(int radius = 5):radius(radius) {}
    void show()
    {
        cout << "radius : "<< this->radius<<endl;
    }
    void showArea()
    {
        float area = 3.14 *this->radius * this->radius;
        cout << "the ares of circle : "<<area<<endl;
    }
    virtual ~Circle()
    {
        cout << "~Circle()" << endl;
    }
    int getRadius() const;
    void setRadius(int value);

private:
    int radius;
};


int main()
{
    cout << "Hello World!" << endl;

    Circle c(5);

    Shape *p = &c;

    p->show();
    p->showArea();

//    Shape &p = c;


    Shape *p1[4] = {new Square(3) ,new Square(4),new Circle(6),new Circle(7)};

    for (int i = 0; i < 4; ++i) {

        p1[i]->show();
        p1[i]->showArea();
    }

    for (int i = 0;i < 4;i++) {
        delete p1[i];
    }

    return 0;
}

void Square::setLength(int value)
{
length = value;
}

int Square::getLength() const
{
return length;
}

int Circle::getRadius() const
{
return radius;
}

void Circle::setRadius(int value)
{
radius = value;
}
