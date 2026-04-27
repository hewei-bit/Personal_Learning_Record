#include <iostream>
#include "student.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    student he("hewei","20141544",100.0);
    student wei = he;

    he.showInfo();

    wei.showInfo();
    return 0;
}
