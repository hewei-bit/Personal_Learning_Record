#include "complex.h"

Complex::Complex(double a, double b):a(a),b(b)
{

}

const Complex Complex::operator +(const Complex &t)
{

    return Complex(this->a + t.a,this->b + t.b);
}



const Complex Complex::operator -(const Complex &t)
{
     return Complex(this->a - t.a,this->b - t.b);
}

const Complex Complex::operator *(const Complex &t)
{
    Complex temp;
    temp.a = (this->a*t.a - this->b*t.b);
    temp.b = (t.a *this->b + this->a*t.b);
     return temp;
}
/*

(a+bi)/(c+di)=(ac+bd)/(c2+d2) +((bc-ad)/(c2+d2))i

*/
const Complex Complex::operator /(const Complex &t)
{
    Complex temp;
    temp.a = ((this->a * t.a) +(this->b*t.b))/(t.a*t.a + t.b *t.b);
    temp.b = (this->b*t.a-this->a*t.b)/(t.a*t.a + t.b *t.b);
     return temp;
}

bool Complex::operator ==(const Complex &t)
{
      //判断this是否与t表示为同一个对象
    if(this->a == t.a && this->b == t.b)
    {
        return  true;
    }else {
        return  false;
    }
}

/*
float locale, r, d ;
const float EPSINON = 0.0000001;
...   //locale和r已被初始化
d = locale - r;

if(d > EPSINON){}  //两浮点数之差大于零的处理
else if(d < -EPSINON) {} //两浮点数之差小于零
else if(d <= fabs(EPSINON)) {} //两浮点数之差等于零

*/
bool Complex::operator !=(const Complex &t)
{
    cout << " Complex::operator != " << endl;
    double d,r;
    d = this->a - t.a;
    r = this->b - t.b;
    if((abs(d) <= EPSINON) || (abs(r) <= EPSINON) ) //两浮点数之差等于零
    {
        return false;
    }else {
        return  true;
    }

}

Complex &Complex::operator =(const Complex &t)
{
       if(this != &t)
       {
           this->a = t.a;
           this->b = t.b;
       }

       return *this;
}

double Complex::getA() const
{
    return  this->a;
}

double Complex::getB() const
{
    return this->b;
}
