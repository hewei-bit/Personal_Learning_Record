#include <iostream>

using namespace std;

#define PI 3.14

inline double area(double radius)
{
    return PI*radius*radius;
}

double calc(double radius,double height = 1.0)
{
//    double result;
    return area(radius)*height/3;
}

int calc(int radius,int height = 1)
{
    int result = ((int)area(radius)*height/3);
    return result;
}


int main()
{
    int radius_i;
    int height_i;
    int result_i;
    double radius_d;
    double height_d;
    double result_d;

    cout <<"please input radius and height by int"<<endl;
//    cin >> radius_i >> height_i;
//    cout << radius_i << height_i;


    result_i = calc(1,2);
    cout << "result = "<<result_i<<endl;

    cout <<"please input radius and height by double"<<endl;
//    cin >> radius_d >> height_d;
//    cout << radius_d << height_d;

    result_d = calc(22.1,34.1);
    cout << "result = "<<result_d<<endl;
    result_d = calc(22);
    cout << "result = "<<result_d<<endl;


    cout << "Hello World!" << endl;
    return 0;
}

