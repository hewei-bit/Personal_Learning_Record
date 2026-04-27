#include <iostream>

using namespace std;

class Programer
{
public:
    virtual void showMoney()
    {
         cout << "Programer::----"  << endl;
    }
    protected:
//private:
    double salary; //如果希望父类的成员能够在子类中访问，在子类外不能访问，可以使用
                    //protected
};

//初级程序员
class primaryProgramer : public Programer
{

public:
    primaryProgramer(double salary)
    {
        this->salary = salary;
    }
   virtual void showMoney()
    {
        cout << "primaryProgramer::" << this->salary << endl;
    }

    void test()
    {
          cout << "primaryProgramer::";
    }
};

class middleProgramer : public Programer
{

public:
    middleProgramer(double salary)
    {
        this->salary = salary;
    }
   virtual void showMoney() //子类中重写父类的虚函数
    {
        cout << "middleProgramer::" << this->salary << endl;
    }

    void test()
    {
          cout << "middleProgramer::";
    }
};

void printSalary(Programer& p) //形参是父类引用 Programer& p = primary
{
   p.showMoney(); //程序在运行时，父类引用在调用这个函数showMoney时，发生多种形态
                   //在发生函数调用时，左边的父类引用或者父类指针会根据实际的对象类型去
                   //调用对象类型的接口函数（查虚函数表，如果表中有该虚函数中，调用，否则，
                   // 查找父类是否有匹配的虚函数）

}
int main()
{
#if 0
    primaryProgramer primary(6000);
    primary.showMoney();

    middleProgramer midlle(10000);
    midlle.showMoney();
    //如果员工人数很多，每个人都要来执行一个showMoney函数
#endif
    primaryProgramer primary(6000);
    printSalary(primary); //实参为子类对象
    middleProgramer midlle(10000);
    printSalary(midlle);
    midlle.test();
    return 0;
}
