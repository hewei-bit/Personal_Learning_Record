#include "employee.h"

int employee::_startNum = 1000;


void employee::disinfor()
{
    cout << "name : "<<this->_name<<endl;
    cout << "num : "<<this->_num<<endl;
    cout << "level : "<<this->_level<<endl;
    cout << "salary : "<<this->_salary<<endl;
}

void employee::promote(int level)
{
    this->_level += level;
}

void employee::init(string name)
{
    _startNum += 1;
    this->_name = name;
    this->_num = _startNum;
    this->_level = 1;
    this->_salary = 0;
}
