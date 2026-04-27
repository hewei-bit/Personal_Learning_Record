#include "technician.h"


Technician::Technician()
{

}

Technician::~Technician()
{

}

void Technician::calcSalary()
{
    m_salary = m_MoneyHour*m_WorkHour*22;
}

void Technician::showInfo()
{
        cout << "员工姓名: "<< m_Name << endl;
        cout << "员工级别："<< m_level << endl;
        cout << "员工工号: "<< m_workNumber << endl;
        cout << "员工薪水: " << m_salary << endl;
}

void Technician::init()
{
      cout << "请输入技术人员姓名:";
      cin>>m_Name;
      cout << "请输入技术人员工作时长:";
      cin>>m_WorkHour;
      m_level = 1;
      m_workNumber = m_startNumber++;
}

void Technician::promote()
{
    m_level += 3;
}
