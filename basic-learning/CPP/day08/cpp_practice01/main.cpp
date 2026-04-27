#include <iostream>

using namespace std;

//编程实现如下的类：
//代表交通工具的类：Vehicle（基类）
//代表汽车的类：Car（一种交通工具交通工具）
//代表船只的类：Boat（一种交通工具交通工具）
//代表水陆两栖装甲车的类：Amphibious（一种既是Car又是Boat的交通工具）
//假设：
//    交通工具都具备行走（move）的功能，这是个虚函数
//    交通工具都具有牌照（ID），获取牌照是个实函数（普通函数）
class Vehicle
{
public:
    Vehicle()
    {
//        cout << "v  ID : "<<ID<<endl;
    }
    virtual void move()
    {
        cout << " vehicle::move "<<endl;
    }
    int ID;
};

class Car:virtual public Vehicle
{
public:
    Car()
    {
        this->ID = 2222;
        cout << "CAR ID : "<<ID<<endl;
    }
    Car(int ID)
    {
        this->ID = ID;
        cout << "ID : "<<ID<<endl;
    }
    void move()
    {
       cout <<" car::move"<<endl;
    }
};

class Boat:virtual public Vehicle
{
public:
    Boat()
    {
        this->ID = 1111;
        cout << " BOAT ID : "<<ID<<endl;
    }
    Boat(int ID)
    {
        this->ID = ID;
        cout << "ID : "<<ID<<endl;
    }
    void move()
    {
        cout <<" boat::move"<<endl;
    }
};

class Amphibious:public Car,public Boat
{
public:
    Amphibious()
    {
        this->ID = 3333;
        cout << "Amphibious ID : "<<ID<<endl;
    }
    Amphibious(int ID)
    {
        this->ID = ID;
        cout << "Amphibious ID : "<<ID<<endl;
    }
    void move()
    {
        cout <<" Amphibious::move"<<endl;
    }
};

class Driver
{
public:
    Driver() {}
    void Drive(Vehicle &vv)
    {
        vv.move();
    }
    void Drive(Vehicle *vv)
    {
        vv->move();
    }
};


int main()
{
    cout << "Hello World!" << endl;
    Amphibious a(3333);
    Car c(1111);
    Boat b(2222);
//    a.move();
//    c.move();
//    b.move();
    Driver dd;
    dd.Drive(a);
    dd.Drive(b);
    dd.Drive(c);

    return 0;
}
