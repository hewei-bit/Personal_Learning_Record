#include <iostream>

using namespace std;

class A
{
public:
    void printT()
    {
        cout << "A::printT()" << endl;
    }

int a;
};

class B:public A
{

public:
    void printT()
    {
        cout << "B::printT()" << endl;
        A::printT(); //告诉程序这个函数是来自于A类，
    }
    int a;
};

int main()
{
   B b;
   b.printT();

    return 0;
}
