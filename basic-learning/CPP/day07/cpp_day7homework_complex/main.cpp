
#include "complex.h"

ostream & operator<<(ostream&os,const Complex& t)
{
    cout << "(" << t.getA() << "+" << t.getB() << "i)" << endl;
    return os;
}
int main()
{
   Complex t1(1,2);
   Complex t2(3,-4);

   Complex t3 = t1 + t2;

   cout << t3;
   Complex t4 = t3;
   cout << t4;

   cout << (t3 == t4);
   cout << t3.operator==(t4);

   cout << (t3 != t4);

    return 0;
}
