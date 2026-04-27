#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <iostream>

using namespace std;

class employee
{
public:
    employee(){

    }
    employee(string name){
        init(name);
    }
    virtual void calcSalary(){}
    virtual void disinfor();
    virtual void promote(int level);
    virtual void init(string name);

protected:
    string _name;
    int _num;
    int _level;
    float _salary;
    static int _startNum;
};



class Technician:public employee
{
public:
    Technician(){}
    Technician(string name):employee(name)
    {
        promote(3);
    }
    Technician(string name,int hour):employee(name)
    {
        calcSalary(hour);
        promote(3);
    }
    void calcSalary(int hour)
    {
        this->_salary = hour*100;
    }


private:

};


class Salesman:virtual public employee
{
public:
    Salesman(){}
    Salesman(string name)
    {
        init(name);
        promote(0);
    }
    Salesman(string name,float salenum)
    {
        init(name);
        calcSalary(salenum);
        promote(0);
    }
    void calcSalary(float salenum)
    {
        this->_salary = salenum * 0.04;
    }
};

class Manager:virtual public employee
{
    public:
    Manager(){}

    Manager(string name)
    {
        init(name);
        calcSalary();
        promote(4);
    }
    void calcSalary()
    {
        this->_salary = 8000;
    }
};

class SaleManager:public Salesman,public Manager
{
public:
    SaleManager(){

    }
    SaleManager(string name)
    {
        init(name);
        promote(3);
    }
    SaleManager(string name,float salenum)
    {
        init(name);
        calcSalary(salenum);
        promote(3);
    }
    void calcSalary(float salenum)
    {
        this->_salary = 5000+salenum*0.05;
    }

};


#endif // EMPLOYEE_H
