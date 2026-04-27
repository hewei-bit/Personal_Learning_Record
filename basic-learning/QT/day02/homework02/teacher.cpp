#include "teacher.h"

teacher::teacher()
{

}

void teacher::setT_name(const string &value)
{
    t_name = value;
}

string teacher::getT_departments() const
{
    return t_departments;
}

void teacher::setT_departments(const string &value)
{
    t_departments = value;
}

string teacher::getT_name() const
{
    return t_name;
}

string teacher::getT_position() const
{
    return t_position;
}

void teacher::setT_position(const string &value)
{
    t_position = value;
}
