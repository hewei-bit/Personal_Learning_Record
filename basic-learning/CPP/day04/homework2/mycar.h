#ifndef MYCAR_H
#define MYCAR_H

#include <iostream>

using namespace std;



//实现一个汽车类（包含颜色，品牌，公里数，剩余油量）
//跑起来的时候显示运行状态（跑的公里数，剩余油量）
//还可以加油
class mycar
{
public:
    mycar(){}
    mycar(string color,string brand,double kilometer,double RemainL,double Fuel_consumption);
    mycar(const mycar &other);
    ~mycar();

    void runnig(int kilometer);

    void fuelUp(int gasoline);

    void showInfo();

    double getRemainL() const;


private:
    const string color;
    const string brand;
    double kilometer;
    double RemainL;
    double Fuel_consumption;
};



#endif // MYCAR_H
