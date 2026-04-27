#include <iostream>
#include "car.h"
using namespace std;




int main()
{
    cout << "Hello World!" << endl;

    electroMobile em(1500,150,600);
    AeroCar ac(1000,500);
    MotorHomes mh(2000,150,3);

    em.charge(200);
    ac.fly();
    mh.camping();

    return 0;
}
