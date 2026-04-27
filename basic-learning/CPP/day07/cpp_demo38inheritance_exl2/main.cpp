#include <iostream>

using namespace std;

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
    Graduate(string name,string sex,int score,int salary
             ):Student(name,sex,score),salary(salary)
    {
     cout << "  Graduate(string name,string sex,int score,"
             "int salary,int year,int month,int day) "  << endl;
    }

    void printG()
    {
        this->printS(); //调用基类中的接口函数

        cout << " salary = " << this->salary << endl;
    }

private:
    int salary;

};

class Doctor:public Graduate
{
public:
    Doctor(string name,string sex,int score,int salary,string title):
        Graduate(name,sex,score,salary),title(title)
    {
        cout << "  Doctor(string name,string sex,"
                "int score,int salary,string title)"
                  << endl;
    }

    void printD()
    {
        printG();
        cout << title << endl;
    }
private:
    string title;
};

int main()
{
   Doctor d("li4","male",100,10000,"Dr.li");
   d.printD();
    return 0;
}
