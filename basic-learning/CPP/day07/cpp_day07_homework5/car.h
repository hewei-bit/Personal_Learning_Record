#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;
//设计一个（Car）类，用来表征一辆汽车，令其包含如下成员：

//成员数据包括：
//质量（mass）
//最高速度（maxSpeed）

//成员方法包括：
//行驶（move）
//维修（maintain）

//以 Car 为基类，设计若干派生类，
//比如电动汽车（ElectroMobile）、飞行汽车（AeroCar）、房车（MotorHomes）等。
//为特定种类的派生类增加新的成员，来表达其新的属性和行为，


class Car
{
public:
    Car(int mass = 1000,int maxSpeed = 180);
    ~Car(){
        cout <<"~Car()"<<endl;
    }
    void move();
    void maintain();


    int getMass() const;
    void setMass(int value);

    int getMaxSpeed() const;
    void setMaxSpeed(int value);

private:
    int mass;
    int maxSpeed;
};
//比如电动汽车有电量（electricQuantity）属性，可以充电（charge）；
class electroMobile:public Car
{
public:
    electroMobile(int mass = 1000,int maxSpeed = 180,int electricQuantity = 600):Car(mass,maxSpeed),electricQuantity(electricQuantity)
    {
        cout <<"electroMobile(int mass = 1000,int maxSpeed = 180)"<<endl;
    }
    ~electroMobile()
    {
        cout <<"~electroMobile()"<<endl;
    }


    void charge(int value)
    {
        electricQuantity += value;
        cout <<"charge"<<endl;
        cout <<"electricQuantity : "<< electricQuantity <<endl;
    }
private:
    int electricQuantity;
};
//飞行汽车可以飞；
class AeroCar:public Car
{
public:
    AeroCar(int mass = 1000,int maxSpeed = 500):Car(mass,maxSpeed)
    {
        cout <<"AeroCar(int mass = 1000,int maxSpeed = 500)"<<endl;
    }
    ~AeroCar()
    {
        cout <<"~AeroCar()"<<endl;
    }



    void fly()
    {
        cout <<"fly()"<<endl;
    }
};

//房车有床位（beds）、卫星电话（satellitePhone），可以宿营（camping）、烹饪（cooking）等。
class MotorHomes:public Car
{
public:
    MotorHomes(int mass = 1000,int maxSpeed = 180,int beds = 0):Car(mass,maxSpeed),beds(beds)
    {
        cout <<"MotorHomes(int mass = 1000,int maxSpeed = 180,int beds = 0)"<<endl;
    }
    ~MotorHomes()
    {
        cout <<"~MotorHomes()"<<endl;
    }

    void satellitePhone()
    {
        cout <<"satellitePhone"<<endl;
    }
    void camping()
    {
        cout <<"camping"<<endl;
    }
    void cooking()
    {
        cout <<"cooking"<<endl;
    }
private:
    int beds;
};

#endif // CAR_H
