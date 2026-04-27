#ifndef SALEMANGER_H
#define SALEMANGER_H
#include "manager.h"
#include "saleman.h"

class SaleManager:public SaleMan,public Manager
{
public:
    SaleManager();
    virtual void calcSalary();//计算员工薪资
    virtual void showInfo(); //显示员工信息
    virtual void init(); //初始化
    virtual void promote(); //提升
};
#endif // SALEMANGER_H
