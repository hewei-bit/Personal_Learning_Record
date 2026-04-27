#include <iostream>

using namespace std;

class C
{
public:
    C()
    {
       cout << "C()" << endl;
    }
    C & operator =(const C & c)
    {
        cout << "C & operator =(const C & c)" << endl;
    }

};

class A
{
public:
    A()
    {
         cout << "A()" << endl;
    }
    A(int a)
    {
       cout << "A(int a=0)" << endl;
       this->a = a;
    }

    void printA()
    {
        cout << "a = " << this->a << endl;
    }

    A & operator =(const A & another)
    {
        this->a = another.a;
        cout <<"A & operator =(const A & another)" << endl;
    }
   private:
    int a;


};

class B : public A
{
 public:
    B(int a,int b):A(a)
    {

        this->b = b;
        cout << "B(int a,int b)" << endl;
    }

    void printB()
    {
        this->printA();
        cout << "b = " << this->b << endl;
    }

    //在派生类中，手动实现了赋值运算符重载
     B & operator =(const B& another)
     {
             cout << " B & operator =(const B& another)" << endl;
         this->b = another.b;
         this->c = another.c;
             //调用父类赋值运算符重载函数
         A::operator =(another); //将子类当作父类来使用，传递给父类的赋值运算符重载函数




     }
private:
    int b;
    C c;

};

int main(int argc, char *argv[])
{
  B b(1,2);
  B bb(3,4);
   bb = b; //赋值操作，对于赋值运算符，系统默认提供一个赋值运算符重载函数

   bb.printB();
    return 0;
}
