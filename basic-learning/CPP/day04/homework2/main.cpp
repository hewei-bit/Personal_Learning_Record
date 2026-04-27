#include <iostream>
#include "mycar.h"
#include "unistd.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    class mycar car("yellow","BMW",100.0,10.0,1.8);
    car.showInfo();

    for (int i = 0;i <10;i++)
    {
        car.runnig(100);
        if(car.getRemainL()<5.0)
        {
            cout << "--------Your car needs gas!!!!----------"<<endl;
            sleep(2);
            car.fuelUp(100);
        }
        sleep(1);
    }





    return 0;
}
