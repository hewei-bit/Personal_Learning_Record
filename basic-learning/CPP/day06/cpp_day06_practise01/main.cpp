#include <iostream>

using namespace std;

//创建一个Circle类，包含类属性 radius，类方法 area。
//再创建一个Cylinder类，
//包含一个Circle类对象成员并增加高度数据成员 height，并实现以下类方法：
//Circle可以设置半径，读取半径，计算圆面积
//Cylinder可以设置圆柱的高，读取圆柱的高，计算圆的表面积，计算圆柱的体积
class Cylindef;

class Circle
{
public:
    Circle() {}
    Circle(int value)
    {
        this->radius = value;
    }
    double circleArea();
    double circumference();
    int getRadius() const;
    
    void setRadius(int value);
    
private:
    int radius;
    
};

class Cylindef
{
public:
    Cylindef() {}
    Cylindef(int value,Circle c1)
    {
        this->height = value;
        this->c1 = c1;
    }

    friend double Circle::circleArea();
    friend double Circle::circumference();
    friend class Circle;

    double surfaceArea()
    {
        double circumference = c1.circumference();
        double circleArea = c1.circleArea();
        double cylinderArea = 2*circleArea+this->height*circumference;
        return cylinderArea;
    }

    double volumn()
    {
        double volumn = c1.circleArea()*this->height;
        return volumn;
    }


    int getHeight() const;
    void setHeight(int value);
    
private:
    Circle c1;
    int height;
};

int main()
{
    cout << "Hello World!" << endl;

    Circle c1(10);
    cout << c1.circleArea()<<endl;
    cout << c1.circumference() <<endl;

    Cylindef cy1(10,c1);
    cout << cy1.surfaceArea() <<endl;
    cout << cy1.volumn() <<endl;
    return 0;
}

double Circle::circleArea()
{
    double area = 3.14*this->radius*this->radius;
    return area;
}

double Circle::circumference()
{
    double circumference = 2*3.14*this->radius;
    return circumference;
}

int Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(int value)
{
radius = value;
}

int Cylindef::getHeight() const
{
return height;
}

void Cylindef::setHeight(int value)
{
height = value;
}
