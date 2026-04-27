
#include "salemanger.h"


SaleManager::SaleManager()
{

}

void SaleManager::calcSalary()
{
  m_salary = m_fixedSalary + m_MonthAmout*m_rate;
}

void SaleManager::showInfo()
{
    cout << "员工姓名: "<< m_Name << endl;
    cout << "员工级别："<< m_level << endl;
    cout << "员工工号: "<< m_workNumber << endl;
    cout << "员工薪水: " << m_salary << endl;
}

void SaleManager::init()
{

}

void SaleManager::promote()
{
    cout <<"请输入销售经理的姓名:";
    cin >> m_Name;
    cout << "请佃入当月的销售额:";
    cin >> m_MonthAmout;
    m_level = 1;
    m_workNumber = m_startNumber++;
    m_fixedSalary = 5000;
    m_rate = 0.05;
}
