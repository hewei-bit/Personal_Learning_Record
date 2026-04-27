#include "calculator.h"

Calculator::Calculator()
{
    inputInfo="";
    temp="";
    RevPolish=new vector<string>;
    oper=new vector<int>;
    resStack=new vector<long double>;
}

Calculator::~Calculator()
{
    if(RevPolish!=nullptr)
    {
        delete RevPolish;
        RevPolish=nullptr;
    }
    if(oper!=nullptr)
    {
        delete oper;
        oper=nullptr;
    }
    if(resStack!=nullptr)
    {
        delete resStack;
        resStack=nullptr;
    }
}

string Calculator::getInputInfo() const
{
    return inputInfo;
}

void Calculator::setInputInfo(const string &value)
{
    inputInfo = value;
}

void Calculator::addInputInfo(const string &value)
{
    inputInfo+=value;
}

void Calculator::clearInputInfo()
{
    inputInfo="";
}

void Calculator::beZeroAll()
{
    inputInfo="";
    temp="";
    RevPolish->clear();
    oper->clear();
    resStack->clear();
}
