#include <iostream>

using namespace std;

//1.由基类student派生出graduate,
//graduate中再嵌套子对象 Birthday,
//如何写出graduate构造函数

class Birthday
{
public:
    Birthday()
    {
        cout <<" Birthday() "<<endl;
    }
    Birthday(string date):date(date)
    {
        cout <<" Birthday(string date) "<<endl;
    }

    void printBirthday()
    {
        cout << " Birthday: "<< date <<endl;
    }

    ~Birthday()
    {
        cout <<" ~Birthday() "<<endl;
    }

    string date;
};


class Student
{
public:
    Student()
    {
        cout << " Student() "<<endl;
    }

    Student(string name):name(name)
    {
        cout << " Student() "<<endl;
    }

    void printName()
    {
        cout << " Student: "<< name <<endl;
    }


    ~Student()
    {
        cout << " ~Student() "<<endl;
    }

    string name;
};



class Gradute:public Student
{
public:
    Gradute()
    {
        cout << " Gradute() "<<endl;
    }



    Gradute(string name,string birthday):Student(name),bd(birthday)
    {
        cout << " Gradute(string name,string birthday) "<<endl;
    }

    ~Gradute(){
        cout << " ~Gradute() "<<endl;
    }

    Birthday bd;
};







int main()
{
    cout << "Hello World!" << endl;
    Gradute he("hewei","19960219");

    he.printName();
    he.bd.printBirthday();


    return 0;
}
