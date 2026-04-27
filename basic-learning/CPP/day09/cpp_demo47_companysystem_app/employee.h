#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

using namespace std;


class Empleyee{

public:
    Empleyee();
    virtual ~Empleyee();

    //对于基类中的虚函数而言，在很多情况下，不会被调用，因为派生类
    //中重写了该虚函数，那么实现它就 没有本身的意义
    //在C++中，有一种更好的解决办法：纯虚函数
    //语法：在类中 定义虚函数为
    // virtual void calcSalary() = 0;
    //如果一个类中，有纯虚函数，那么这个类就是一个抽象类，抽象类的特点就是不能实例对象
    //Empleyee e; //error
    virtual void calcSalary() = 0;//计算员工薪资
    virtual void showInfo() = 0; //显示员工信息
    virtual void init() = 0; //初始化
    virtual void promote() = 0; //提升

protected:
    string m_Name; //员工的姓名
    int m_workNumber; //员工的编号
    int m_level;//员工的等级
    float m_salary;//员工的薪水

    static int m_startNumber; //对于每个员工都是共享，用来累计公司员工数目
};


#endif // EMPLOYEE_H
