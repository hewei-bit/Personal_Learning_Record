#include <iostream>

using namespace std;
//实现一个复数类，并实现以下操作符重载
//复数有实部和虚部
//可以进行的运算操作符：
//+，-，*，/
//比较操作符:== ,!=
//赋值操作符:=



class Complex
{
public:
    Complex(float real = 0,float imag = 0);
    Complex(const Complex& complex);
    ~Complex(){}

    Complex operator +(const Complex& complex);
    Complex operator -(const Complex& complex);
    Complex operator *(const Complex& complex);
    Complex operator /(const Complex& complex);
    bool operator ==(const Complex& complex);
    bool operator !=(const Complex& complex);
    Complex & operator = (const Complex & complex);

    float getReal() const;

    float getImag() const;

private:
    float real;
    float imag;
};

int main()
{
    cout << "Hello World!" << endl;
    Complex a(1,1);
    Complex b(2,2);

    cout << a.getReal() << " + " <<a.getImag()<<"i" <<endl;
    cout << b.getReal() << " + " <<b.getImag()<<"i" <<endl;

    Complex c;
    Complex d;
    Complex e;
    Complex f;
    Complex g;
    bool BOOL;

    c = a+b;
    cout << "c = a+b   ---> ";
    cout << c.getReal() << " + " <<c.getImag()<<"i" <<endl;
    d = a-b;
    cout << "d = a-b   ---> ";
    cout << d.getReal() << " + " <<d.getImag()<<"i" <<endl;
    e = a*b;
    cout << "e = a*b   ---> ";
    cout << e.getReal() << " + " <<e.getImag()<<"i" <<endl;
    f = a/b;
    cout << "f = a/b   ---> ";
    cout << f.getReal() << " + " <<f.getImag()<<"i" <<endl;
    d = c;
    cout << "d = c  ---> ";
    cout << d.getReal() << " + " <<d.getImag()<<"i" <<endl;

    BOOL = (a == b);

    cout << "a == b  ---> " << BOOL <<endl;

    BOOL = (a != b);
;
    cout << "a != b  ---> " << BOOL <<endl;

    return 0;
}

Complex::Complex(float real, float imag):real(real),imag(imag){}

Complex::Complex(const Complex &complex)
{
    this->real = complex.real;
    this->imag = complex.imag;
}

Complex Complex::operator +(const Complex &complex)
{
    Complex temp;
    temp.real = this->real + complex.real;
    temp.imag = this->imag + complex.imag;
    return temp;
}

Complex Complex::operator -(const Complex &complex)
{
    Complex temp;
    temp.real = this->real - complex.real;
    temp.imag = this->imag - complex.imag;
    return temp;
}

Complex Complex::operator *(const Complex &complex)
{
    Complex temp;
    temp.real = this->real * complex.real - this->imag * complex.imag;
    temp.imag = complex.real*this->imag * this->real*complex.imag;
    return temp;
}

Complex Complex::operator /(const Complex &complex)
{
    Complex temp;
    temp.real = (this->real*complex.real+this->imag*complex.imag) / (complex.real*complex.real+complex.imag*complex.imag);
    temp.imag = (complex.real*this->imag-this->real*complex.imag) / (complex.real*complex.real+complex.imag*complex.imag);
    return temp;
}

bool Complex::operator ==(const Complex &complex)
{
    return (this->real == complex.real) && (this->imag == complex.imag) ;
}

bool Complex::operator !=(const Complex &complex)
{
    return (this->real != complex.real) && (this->imag != complex.imag) ;
}

Complex &Complex::operator =(const Complex &complex)
{
    if(this != &complex)
    {
        this->real = complex.real;
        this->imag = complex.imag;
    }
    return *this;
}

float Complex::getReal() const
{
return real;
}

float Complex::getImag() const
{
return imag;
}
