#include "teacher.h"

Teacher::Teacher(const string &name, int no, const string &sex, int age):
    m_name(name),m_no(no),m_sex(sex),m_age(age)
{

}

string Teacher::name() const
{
    return m_name;
}

int Teacher::no() const
{
    return m_no;
}

string Teacher::sex() const
{
    return  m_sex;
}

int Teacher::age() const
{
    return m_age;
}
