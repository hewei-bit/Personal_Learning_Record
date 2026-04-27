#include "teacher.h"


Teacher::Teacher()
{

}

Teacher::Teacher(string name, string department, string duty)
{
    this->m_duty = duty;
    this->m_name = name;
    this->m_department = department;
}

string Teacher::name() const
{
    return m_name;
}

string Teacher::department() const
{
    return  m_department;
}

string Teacher::duty() const
{
    return m_duty;
}




