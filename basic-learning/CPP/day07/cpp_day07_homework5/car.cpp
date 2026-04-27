#include "car.h"


Car::Car(int mass, int maxSpeed):mass(mass),maxSpeed(maxSpeed){
    cout <<"Car(int mass = 1000,int maxSpeed = 180)"<<endl;
}

void Car::move()
{
    cout <<"move()"<<endl;
}

void Car::maintain()
{
    cout <<"maintain()"<<endl;
}

int Car::getMass() const
{
    return mass;
}

void Car::setMass(int value)
{
    mass = value;
}

int Car::getMaxSpeed() const
{
    return maxSpeed;
}

void Car::setMaxSpeed(int value)
{
    maxSpeed = value;
}
