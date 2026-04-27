#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager:virtual public Empleyee
{
public:
    Manager();
    ~Manager();
    virtual void calcSalary();//计算员工薪资
    virtual void showInfo(); //显示员工信息
    virtual void init(); //初始化
    virtual void promote(); //提升
protected:
    int m_fixedSalary;
};
#endif // MANAGER_H
