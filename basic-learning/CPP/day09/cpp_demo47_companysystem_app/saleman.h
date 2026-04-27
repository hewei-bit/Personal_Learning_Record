#ifndef SALEMAN_H
#define SALEMAN_H
#include "employee.h"
class SaleMan:virtual public Empleyee
{
public:
    SaleMan();
    ~SaleMan();

    virtual void calcSalary();//计算员工薪资
    virtual void showInfo(); //显示员工信息
    virtual void init(); //初始化
    virtual void promote(); //提升

protected:
    int m_MonthAmout; //销售额
    float m_rate; //提成率
};
#endif // SALEMAN_H
