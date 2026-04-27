#include "saleman.h"


SaleMan::SaleMan()
{

}

SaleMan::~SaleMan()
{

}

void SaleMan::calcSalary()
{
    m_salary = m_MonthAmout * m_rate;
}

void SaleMan::showInfo()
{
    cout << "员工姓名: "<< m_Name << endl;
    cout << "员工级别："<< m_level << endl;
    cout << "员工工号: "<< m_workNumber << endl;
    cout << "员工薪水: " << m_salary << endl;
}

void SaleMan::init()
{
    cout << "请输入销售员工的姓名:";
    cin >> m_Name;
    cout << "请输入当月的销售额:";
    cin >> m_MonthAmout;
    m_level = 1;
    m_workNumber = m_startNumber++;
    m_rate = 0.04;

}

void SaleMan::promote()
{
   m_level += 1;
}
