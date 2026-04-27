#include <iostream>

using namespace std;

class Birthday
{
public:
    Birthday(int year,int month,int day):
        year(year),month(month),day(day)
    {
        cout << " Birthday(int year,int month,int day)" << endl;
    }
    void printB()
    {
        cout << " year :" << this->year << endl;
        cout << " month :" << this->month << endl;
        cout << " day : " << this->day << endl;
    }
private:
    int year;
    int month;
    int day;
};

class Student{
public:
    Student(string name="",string sex = " ",int score = 0):
        name(name),sex(sex),score(score)
    {
        cout << " Student(string name="",string sex = " ",int score = 0)" << endl;
    }
    void printS()
    {
        cout << " name :" << this->name << endl;
        cout << " sex :" << this->sex << endl;
        cout << " score : " << this->score << endl;
    }
private:
    string name;
    string sex;
    int score;
};

class Graduate :public Student
{
public:
    Graduate(string name,string sex,int score,int salary,
             int year,int month,int day):Student(name,sex,score),bir(year,month,day)
      ,salary(salary)
    {
     cout << "  Graduate(string name,string sex,int score,"
             "int salary,int year,int month,int day) "  << endl;
    }

    void printG()
    {
        this->printS(); //调用基类中的接口函数
        bir.printB();
        cout << " salary = " << this->salary << endl;
    }

private:
    int salary;
    Birthday bir;
};
int main()
{
  Graduate g("zhang3","male",99,1000,2020,6,19);
  g.printG();
    return 0;
}
