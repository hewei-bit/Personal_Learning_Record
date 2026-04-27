#include "loginmainwindow.h"
#include "ui_loginmainwindow.h"
#include <QtDebug>

LoginMainWindow::LoginMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginMainWindow)
{
    ui->setupUi(this);
    //通过代码来设置对象的属性
    ui->userLabel->setStyleSheet("background-color: rgb(255, 0, 0);"); //set方法
    qDebug()<< ui->userLabel->styleSheet(); //相当于get方法
}

LoginMainWindow::~LoginMainWindow()
{
    delete ui;
}
