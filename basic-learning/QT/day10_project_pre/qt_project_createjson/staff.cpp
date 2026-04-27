#include "staff.h"

Staff::Staff()
{

}

Staff::~Staff()
{

}

void Staff::setAge(const QString &age)
{
   m_age = age;
}

QString Staff::age() const
{
    return  m_age;
}

void Staff::setName(const QString &name)
{
    m_name = name;
}

QString Staff::name() const
{
    return  m_name;
}

void Staff::setMoney(const QString &money)
{
    m_money = money;
}

QString Staff::money() const
{
    return  m_money;
}
