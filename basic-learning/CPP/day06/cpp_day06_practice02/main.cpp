#include <iostream>

using namespace std;


class A
{
public:
    A(){}
    A(int a)
    {
        this->a = a;
    }
    A operator+(A &a1)
    {
        A temp;
        temp.a = this->a+a1.a;
        return temp;
    }
    A operator*(A &a1)
    {
        A temp;
        temp.a = this->a*a1.a;
        return temp;
    }
    A operator-(A &a1)
    {
        A temp;
        temp.a = this->a-a1.a;
        return temp;
    }

    A operator/(A &a1)
    {
        A temp;
        temp.a = this->a/a1.a;
        return temp;
    }

    int getA() const;


private:
    int a;
};


int main()
{
    cout << "Hello World!" << endl;

    A a1(1);
    A a2(2);
//    A a3 = a1+a2;
    A a3 = a1.operator+(a2);
//    A a4 = a3*a2;
    A a4 = a3.operator*(a2);
    A a5 = a4 - a3;
    A a6 = a5/a2;
    cout << a3.getA()<<endl;
    cout << a4.getA() <<endl;
    cout << a5.getA() <<endl;
    cout << a6.getA() <<endl;
    return 0;
}

int A::getA() const
{
return a;
}
