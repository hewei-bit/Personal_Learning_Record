#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>

using namespace std;

class teacher
{
public:
    teacher();
    teacher(string name,string departments,string position):
        t_name(name),t_departments(departments),t_position(position)
    {}

    string getT_name() const;
    void setT_name(const string &value);

    string getT_departments() const;
    void setT_departments(const string &value);

    string getT_position() const;
    void setT_position(const string &value);

private:
    string t_name;
    string t_departments;
    string t_position;
};

#endif // TEACHER_H
