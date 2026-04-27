#include <iostream>
#include "employee.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Technician a("hewei",100);
//    a.calcSalary(100);
    a.disinfor();
    cout << endl;
    Salesman b("511",20000);
//    b.calcSalary(20000);
    b.disinfor();
    cout << endl;
    Manager c("155");
    c.calcSalary();
    c.disinfor();
    cout << endl;
    SaleManager d("wei",200000);
//    d.calcSalary(200000);
    d.disinfor();
    cout << endl;
    return 0;
}
