#ifndef TECHNICIAN_H
#define TECHNICIAN_H
#include "employee.h"

//认为一个员工入职，从公司的角度，他就是一个小白
class Technician: public Empleyee
{

public:
    Technician();
    ~Technician();
    //重写父类中的虚函数
    virtual void calcSalary();//计算员工薪资
    virtual void showInfo(); //显示员工信息
    virtual void init(); //初始化
    virtual void promote(); //提升

private:
    int m_WorkHour;
    const int m_MoneyHour = 100; //此写法在C++11新特性才支持，或者要通过构造函数初始化列表来初始化
};

#endif // TECHNICIAN_H
