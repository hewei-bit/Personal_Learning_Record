#include <iostream>

using namespace std;

/*
default (1)	string(); //无参构造函数
copy (2)	string (const string& str); //拷贝构造函数
substring (3)	string (const string& str, size_t pos, size_t len = npos); //插入子字符串构造函数
from c-string (4)	string (const char* s);  接受C语言字符串，转换成string对象
from buffer (5)	string (const char* s, size_t n);
fill (6)	string (size_t n, char c);
range (7)	template <class InputIterator>
  string  (InputIterator first, InputIterator last);
initializer list (8)	string (initializer_list<char> il);
move (9)	string (string&& str) noexcept;


*/
class Person
{
public:
    //对于编译器来，将显示的构造函数传入一个隐式的Person*const this指针
    //Person(Person*const this,int age,char sex,string name)
    Person(int age = 0,char sex = 'M',string name = "zhang3")
        :age(age),sex(sex),name(name)
    {
        //可以显示的使用this指针,是该函数中的局部变量
//        this->age = age;
//        this->sex = sex;
//        this->name = name;


    }

    void printP() //void printP(Person*const this)
    {
        cout << "age = " << this->age << "name = " << this->name << "sex = " << this->sex << endl;
    }
private:
    int age;
    char sex;
    //在C++中,使用string类来处理字符串,代换C语言的char* 和 char []
    string name;


};
int main()
{
//   string s; //无参构造函数
//   string s1 = s; //拷贝构造函数
//   string s2("helloworld");
//   cout << s2 << endl;
   // string s3 = "hello"; 使用是的运算符和重载

    Person p(20,'M',"li4"); //p(20,'M',"li4");
    p.printP(); // p.printP(&p);
    cout << hex << &p << endl;
    Person p1(18,'W',"wang5");
    p1.printP();
    return 0;
}
