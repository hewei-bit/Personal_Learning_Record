#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Calculator
{
    friend class MainWindow;
public:
    Calculator();
    ~Calculator();
    string getInputInfo() const;
    void setInputInfo(const string &value);
    void addInputInfo(const string &value);
    void clearInputInfo();      //清空输入
    string returnOper(const int id);    //接收按钮的id值，返回id值对应的运算符字符串
    void beZeroAll();   //全部成员清零

private:
    string inputInfo;       //存放所有的输入

    vector<int> *oper;  //运算符容器

    vector<long double> *resStack;  //逆波兰表达式运算栈

    vector<string> *RevPolish;      //逆波兰表达式存放栈

    string temp;        //当输入遇到运算符时，提取之前输入的数字


};

#endif // CALCULATOR_H
