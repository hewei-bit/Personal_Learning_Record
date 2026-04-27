#include <iostream>

using namespace std;

class A{
public:
    friend ostream & operator<<(ostream&os,const A& a);
    A(int a = 0)
    {
        this->a = a;
    }
    int getA()const
    {
        return this->a;
    }
private:
    int a;
};

//方法一 左操作数为ostream --cout 右操作数为自定义类类型
ostream & operator<<(ostream&os,const A& a1)
{
    cout << "a = " << a1.a << endl;
    return os;
}

int main()
{
  A a1(10);

  cout << a1.getA() << endl;
  cout << a1 << endl;
  int i;
  cin >> i;

    return 0;
}
