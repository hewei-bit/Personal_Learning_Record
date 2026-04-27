/*作业二：设计一个圆锥体，
 * 可以计算一个圆锥体的体积*/

#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14

class cone
{
public:
    double height;
    double radius;
    void volume()
    {
        double area;
        area = PI*pow(radius,2)*height/3;
        cout <<"the volume of cone is "<<area << endl;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    cone cc;
    cc.radius = 11;
    cc.height = 22;
    cc.volume();


    return 0;
}
