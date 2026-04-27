#include "manager.h"


Manager::Manager()
{

}

Manager::~Manager()
{

}

void Manager::calcSalary()
{
  m_salary = m_fixedSalary;
}

void Manager::showInfo()
{
    cout << "员工姓名: "<< m_Name << endl;
    cout << "员工级别："<< m_level << endl;
    cout << "员工工号: "<< m_workNumber << endl;
    cout << "员工薪水: " << m_salary << endl;
}

void Manager::init()
{
    cout << "请输入经理的姓名:";
    cin >> m_Name;
    m_level = 1;
    m_workNumber = m_startNumber++;
    m_fixedSalary = 8000;
}

void Manager::promote()
{
   m_level +=4;
}
