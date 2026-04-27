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

int main()
{
    GradeStudent he("he",90);
    he.average(he.getGrade());
    he.setNum(he.getNum()+1);

    GradeStudent wei("wei",80);
    wei.average(wei.getGrade());
    wei.setNum(wei.getNum()+1);

    GradeStudent hewei("hewei",70);
    hewei.average(hewei.getGrade());
    hewei.setNum(hewei.getNum()+1);

    GradeStudent hewei_1("hewei_1",75);
    hewei_1.average(hewei_1.getGrade());
    hewei_1.setNum(hewei_1.getNum()+1);

    GradeStudent hewei_2("hewei_2",75);
    hewei_2.average(hewei_2.getGrade());
    hewei_2.setNum(hewei_2.getNum()+1);

    return 0;
}

GradeStudent::GradeStudent(string name, int grade):name(name)
{
    this->grade = grade;
}

void GradeStudent::average(int grade)
{
    averageGrade=(averageGrade*num+grade)/(num+1);
    cout << "average_grade: "<< averageGrade<<endl;
}

int GradeStudent::getGrade() const
{
    return grade;
}

int GradeStudent::getNum()
{
    return num;
}

void GradeStudent::setNum(int value)
{
    num = value;
}
