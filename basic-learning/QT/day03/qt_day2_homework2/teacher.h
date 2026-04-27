#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
using namespace std;

class Teacher
{

public:
    Teacher();
    Teacher(string name,string department,string duty);
    string name()const;
    string department()const;
    string duty()const;

private:
    string m_name;
    string m_department;
    string m_duty;
};
#endif // TEACHER_H
