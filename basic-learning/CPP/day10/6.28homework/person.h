#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;
class Person
{
public:
    Person(){}
    Person(string name,int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};


#endif // PERSON_H
