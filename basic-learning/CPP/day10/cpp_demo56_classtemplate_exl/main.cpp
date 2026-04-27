#include <iostream>
#include "mystack.hpp"

using namespace std;

class Test
{
public:
    Test(int a = 0)
    {
        this->a = a;
    }
    int getA()const
    {
        return  this->a;
    }
private:
    int a;
};
int main()
{

    //使用容器来存放一个string
   Stack<string> s;
  // string s1("hello");
   s.push("hello");
   s.push("world");

   while (!s.isEmpty()) {
       cout << s.pop() << endl;

   }

   Test t1(1),t2(2);
   Stack<Test> t;
   t.push(t1);
   t.push(t2);

   while (!t.isEmpty()) {
     //  cout << t.pop() << endl;
       Test tt = t.pop();
       cout << tt.getA() << endl;

   }

   Stack<int> ti;
   for (int i =0;i<10;i++) {
       ti.push(i);
   }


   while (!ti.isEmpty()) {

       cout << ti.pop() << endl;
   }

    return 0;
}
