
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;
const double EPSINON = 0.000001;
class  Complex
{
public:
    Complex(double a = 0,double b = 0);

    // + - * /
    const Complex operator +(const Complex& t); //成员函数做为重载，传递就是为R（右操作数）
    const Complex operator -(const Complex& t);
    const Complex operator *(const Complex& t);
    const Complex operator /(const Complex& t);

    //== !=
    bool operator ==(const Complex& t);
    bool operator !=(const Complex& t);

    //=
    Complex& operator =(const Complex& t);
    double getA()const;
    double getB()const;
private:
    double a;
    double b;
};
#endif // COMPLEX_H
