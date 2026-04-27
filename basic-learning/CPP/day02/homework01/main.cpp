/*作业一：设计一个圆形类，和一个点类，
 * 可以计算的圆面积并且判断点和圆关系*/

#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14

class circle
{
public: 
    void isinCircle(const double &xx,const double &yy);
    void myArea();
private:
    double radius = 5;
    double x = 0;
    double y = 0;

};



class point
{
    public:
    double x;
    double y;
};




int main()
{
    cout << "Hello World!" << endl;
    point p0,p1,p2;
    circle c;

    p0.x = 0;
    p0.y = 0;

    p1.x = 5.0;
    p1.y = 0.0;

    p2.x = 5.0;
    p2.y = 5.0;

    c.myArea();

    c.isinCircle(p0.x,p0.y);

    c.isinCircle(p1.x,p1.y);

    c.isinCircle(p2.x,p2.y);



    return 0;
}

void circle::isinCircle(const double &xx, const double &yy)
{
    double distance = abs(sqrt(pow(xx-x,2)+pow(yy-y,2)));
//    cout <<pow(xx-x,2)<<endl;
//    cout << sqrt(pow(xx-x,2)+pow(yy-y,2))<<endl;
    cout <<"distance :"<<distance<<endl;
    if(distance<5)
    {
        cout << "the point is in the circle"<<endl;
    }
    else if(distance == 5.0)
    {
        cout << "the point is on the edge of circle"<<endl;
    }
    else
    {
        cout << "the point is out of circle"<<endl;
    }
}

void circle::myArea()
{
    double area = PI*radius*radius;
    cout<<"the area of circle is "<<area<<" "<<endl;
}
