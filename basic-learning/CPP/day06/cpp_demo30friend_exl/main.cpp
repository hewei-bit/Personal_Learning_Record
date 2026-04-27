#include <iostream>

using namespace std;
//class Cylinder;
class Circle
{

public:
    Circle(){
        cout << "Circle()" <<endl;
    }
    friend class Cylinder; //将该类声明为友元类
    //friend float Cylinder::calSurfaceArea();
    Circle(float radius):radius(radius)
    {
        cout << "Circle(float radius)" <<endl;
    }
    float getRadius() const;
    void setRadius(float value);
    float calArea(float radius)
    {

        return (3.14 * radius *radius);
    }
private:
    float radius;
};


class Cylinder
{
public:
    // int& i = j;  如果是内置类型，效率是一样，就是一个值的传递 int i = j;
   // Cylinder(Circle& c,int height):c(c),height(height)
    Cylinder(Circle& c,int height) //引用对象c本质上就是Circle类型一个对象的别名
    {
        cout << " Cylinder(Circle& c,int height)" <<endl;
        this->c = c;
        this->height = height;
    }

    int getHeight() const;
    void setHeight(int value);
    float calSurfaceArea()
    {
        return (2 *3.14 *c.radius*c.radius + 2 *3.14 *c.radius*this->height);
    }
    float calVolume()
    {
        return (3.14 *c.radius*c.radius *this->height);
    }
private:
    Circle c; //类类型 在申请分配Cylinder空间，要实例化c ---调用该类的无参的构造函数
    int height;
};
int main()
{
   Circle c(5);
   cout << "area = " << c.calArea(c.getRadius())<<endl;

   Cylinder cy(c,10);
   cout << "surfaceArea = " << cy.calSurfaceArea()<<endl;
   cout << "volume = " << cy.calVolume() << endl;
    return 0;
}

float Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(float value)
{
    radius = value;
}

int Cylinder::getHeight() const
{
return height;
}

void Cylinder::setHeight(int value)
{
height = value;
}
