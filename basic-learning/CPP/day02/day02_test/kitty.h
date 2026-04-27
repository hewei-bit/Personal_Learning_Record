#ifndef KITTY_H
#define KITTY_H
#include <iostream>
using namespace std;
enum color{white,gold,brown,variegated};
class kitty
{
public:
    void eat(); //在类中声明成员函数
    void sleep();
    void actingCute();
    void showInfo();
    void test();
    float getWeight() const;
    void setWeight(float value);

    char getSex() const;
    void setSex(char value);

    color getFurcolor() const;
    void setFurcolor(const color &value);

private:
    float weight;
    char sex;
    enum color furcolor;
};
#endif // KITTY_H
