#include <iostream>

using namespace std;


class Base
{
public:
     Base(){cout <<  "B" << endl;}
    ~Base(){cout << "~B" << endl;}
};

class Derived : public Base
{
public:
    Derived() {cout <<  "D" << endl;}
    ~Derived(){cout << "~D" << endl;}
};

int main(void)
{
    Derived d;
}
