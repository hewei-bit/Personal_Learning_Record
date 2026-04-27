#include <iostream>

using namespace std;
class Vehicle
{

public:
    Vehicle(string id = "")
    {
        this->id = id;
    }
    virtual void move()
    {
        cout << "Vehicle---move...." << endl;
    }
   string getId()const
    {
        return id;
    }
  void setId(const string id)
  {
      this->id = id;
  }

private:
    string id;
};

class Car:public Vehicle
{
public:
    Car(string id = ""):Vehicle(id)
    {

    }
    void move()
    {
        cout << "Car---在陆地上跑...." << endl;
    }
};

class Boat:public Vehicle
{
public:
    Boat(string id = ""):Vehicle(id)
    {

    }
    void move()
    {
        cout << "Boat---在水地上跑...." << endl;

    }

};

class Amphibious:public Car,public Boat
{
public:
    Amphibious(string id =""):Car(id)
    {

    }
    void moveTo()
    {
       cout << "Boat---在水地上跑...." << endl;
        cout << "Car---在陆地上跑...." << endl;
    }
    void test()
    {
        //this->move(); //error 要采用虚继承来解决
    }
};
int main()
{
   Car car("123456");
   car.move();

   Boat boat("111111");
   boat.move();

   Amphibious a("22222");
    a.moveTo();


    return 0;
}
