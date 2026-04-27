#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QPushButton>
#include "calculator.h"
#include <cmath>
#include "QDebug"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetFont(int value);    //设置showLabel的字体
    void operJudge(int id);     //判断运算符是否符合出栈入栈条件，用来配合oper和RevPolish生成逆波兰表达式
    void beZeroAll();       //所有限制位归零


private:
    Ui::MainWindow *ui;
    QButtonGroup *btnGroup;
    Calculator *calculator;

    int typePer;    //运算符输入限制位：0->解锁  1->锁定
    int pointPer;   //'.'输入限制位，0->解锁，1->锁定，限制出现运算符或括号前出现两个 .
    int leftNum;   //记录'('个数，只有输入了匹配个数的')'后，才能进行运算
    int rightPer;   //限制')'后的输入,1->解锁，0->锁定
    int perRight;   //')'输入限制位,1->解锁,0->锁定

public slots:
    void btnClicked(const int id);  //按钮点击信号的接收槽

};
#endif // MAINWINDOW_H
