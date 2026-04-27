#include <iostream>

using namespace std;

//2.多层派生：由基类student派生出graduate，
//再由graduate派生出doctor类
//写出doctor类构造函数和graduate派生构造函数

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

class Doctor:public Gradute
{
public:
    Doctor()
    {
        cout << " Doctor() " << endl;
    }
    Doctor(string name,string birthday,int age):Gradute (name,birthday),age(age)
    {
        cout << " Doctor(string name,string birthday,int age) " << endl;
    }

    void printAge()
    {
        cout << " age : "<< age<<endl;
    }

    ~Doctor()
    {
        cout << " ~Doctor() " << endl;
    }

    int age;

};

int main()
{
    cout << "Hello World!" << endl;

    Doctor he("hewei","19960219",24);
    he.printName();
    he.bd.printBirthday();
    he.printAge();

    return 0;
}
