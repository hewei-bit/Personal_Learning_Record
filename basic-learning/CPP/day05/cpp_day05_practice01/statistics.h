#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
using namespace std;



class GradeStudent
{
public:
    GradeStudent(string name,int grade);
    static void average(int grade);
    int getGrade() const;

    static int getNum();

    static void setNum(int value);

private:
    const string name;
    int grade;
    static int averageGrade;
    static int num;
};

int GradeStudent::num = 0;
int GradeStudent::averageGrade = 0;










#endif // STATISTICS_H
