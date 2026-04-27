#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;
class student
{
   public:
    student (){}
    student(string name,string id,float score):id(id),name(name)
    {
        this->score = score;
    }
    student(const student&other);
    ~student(){}


    void showInfo();

    string getId()const;
    string getName()const;
    float getScore();

private:
    const string id;
    const string name;
    float score;
};
#endif // STUDENT_H
