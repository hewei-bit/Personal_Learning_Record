#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include <QString>
using namespace std;

//数据模型：数据可以来源于数据库，文件，网络服务器
class Teacher
{
public:
    Teacher(const string&name,int no,const string & sex,int age);
   // void setName(const string& name);
    string name()const;
    int no()const;
    string sex()const;
    int age()const;

private:
   string m_name;
   int m_no;
   string m_sex;
   int m_age;

   //QString tt;
};
#endif // TEACHER_H
