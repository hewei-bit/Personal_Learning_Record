#include <iostream>

using namespace std;
class Animal
{

public:
    //[2] 父类的虚函数,并且在子类中对虚函数进行重写
    virtual void eat()
    {
        cout << " Animal::eat()" <<endl;
    }
    void sleep()
    {
         cout << " Animal::sleep()" <<endl;
    }
    string skin; //肤色
};

//[1] 多态要有继承
//class Dog:public Animal
//{

//public:
//    virtual void eat()
//    {
//        cout << " Dog::eat()" <<endl;
//    }
//};

class Cat:public Animal
{

public:
    //重写（overwrite）父类的虚函数
    virtual void eat()
    {
        cout << "Cat::eat()" <<endl;
    }
};

// 主人喂养宠物 ---使用同样的接口
//void feed(Animal* a)
//{
//    a->eat();
//}
class Person
{

public:
    //人就兴趣爱好
    void feed(Animal* a)
    {
        a->eat();
    }

    void feed(Animal& a)
    {
        a.eat();
    }
};
//2020年，倒霉，暂时不喂养宠物


//2030年  定义的新的功能
class Snake : public Animal
{

    //重写（overwrite）父类的虚函数
    virtual void eat()
    {
        cout << "Snake::eat()" <<endl;
    }
};

int main()
{
    //[3]父类指针或者父类引用指向子类对象

    //买了宠物 --- DOG
   // Dog d;

    //喂养
    //feed(&d);

    //因为狗会咬人，喂养猫
   // Cat c;
   // feed(&c);
    //体 现的程序的灵活性，因为，改变了对象 但是，该接口依然可以使用

    //经过多年以后，增加新的功能
    Snake s;
     //feed(&s);
    //定义主人
    Person p;
    p.feed(s);


    return 0;
}
