#include "student.h"

student::student(const student &other):id(other.id),name(other.name)
{
    this->score = other.score;
}

void student::showInfo()
{
    cout << "id = "<< getId()<< endl;
    cout << "name = "<< getName()<< endl;
    cout << "score = "<<getScore()<< endl;
}

string student::getId() const
{
    return this->id;
}

string student::getName() const
{
    return this->name;
}

float student::getScore()
{
    return this->score;
}
