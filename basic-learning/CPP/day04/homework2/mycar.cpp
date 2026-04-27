#include "mycar.h"



mycar::mycar(string color, string brand, double kilometer, double RemainL, double Fuel_consumption)
    :color(color),brand(brand)
{
    this->kilometer= kilometer;
    this->RemainL= RemainL;
    this->Fuel_consumption= Fuel_consumption;
}

mycar::mycar(const mycar &other):color(other.color),brand(other.brand)
{
    this->kilometer= other.kilometer;
    this->RemainL= other.RemainL;
    this->Fuel_consumption= other.Fuel_consumption;
}

mycar::~mycar()
{
    cout << "------------车没了-----------" << endl;
}

void mycar::runnig(int kilometer)
{
    cout << "-------------your car is running-----------"<<endl;
    this->kilometer += kilometer;
    cout << "mileage : " <<this->kilometer<<endl;
    this->RemainL -= kilometer*(this->Fuel_consumption)/100;
    cout << "RemainL : " <<this->RemainL<<endl;
}

void mycar::fuelUp(int gasoline)//加油
{
    cout << "-------------Your car is getting gas-----------"<<endl;
    this->RemainL += gasoline;
    cout << "RemainL :"<<this->RemainL<<endl;
    cout << "-------------Your car refueled successfully-----------"<<endl;
}

void mycar::showInfo()//显示车辆信息
{
    cout <<"color: " << this->color<<endl;
    cout <<"brand: " << this->brand<<endl;
    cout <<"kilometer: " << this->kilometer<<endl;
    cout <<"RemainL: " << this->RemainL<<endl;
    cout <<"Fuel_consumption: " << this->Fuel_consumption<<endl;
}

double mycar::getRemainL() const
{
    return this->RemainL;
}
