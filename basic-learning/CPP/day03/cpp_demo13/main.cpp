#include <iostream>

using namespace std;
class circle
{
public:
    circle()
    {
        dir = 0;
       cout << "circle() " << endl;
    }
    circle(const int d)
    {
        dir = d;
        cout << "circle(const int d) " << endl;
    }
    circle(const circle& other)
    {
        dir = other.dir;
        cout << "circle(const circle& other) " << endl;
    }
    float calPerimeter(int dir = 0)
    {
        return (2 * 3.14 * dir);
    }
    float calArea(int dir = 0)
    {
        return (3.14 * dir * dir);
    }
private:
    int dir;
};

class Point{
public:
    //构造函数支持函数的默认参数
   // Point(int x_t = 0,int y_t = 0, const circle& c_t = 0)
    Point(const circle c_t,int x_t = 0,int y_t = 0 )
    {
        cout << "Point(int x_t = 0,int y_t = 0) " << endl;
        x = x_t;
        y = y_t;
        c = c_t;
    }
 //ctrl + / 多行注释，再一次按，取消多行注释
    Point(const Point & other)
    {
        x = other.x;
        y = other.y;
        cout << " Point(const Point & other)" <<endl;
    }
private:
    int x;
    int y;
    circle c; //创建一个对象c
};
int main()
{
    circle c;
    //circle c2 = c;
    circle c1(5);

    Point p5(c1,3,4);
//    //类类型
//    Point p;
//    Point p2(3,4);
//    Point p3 = p; //在创建对象时， 使用一个对象来给另一个对象进行初始化
//    Point p4; //创建对象P4时，会调用无参构造函数
//    p4 = p;
//    //内置类型
//    int i = 1;
//    int j = i;
    return 0;
}
