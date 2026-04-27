#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

// connect(sender, &QObject::destroyed, this, &MyObject::objectDestroyed);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // qDebug() << ui->loginBtn->isEnabled(); //得到UI组件的使能状态
   // ui->loginBtn->setEnabled(true); //设置当前ui->loginBtn表示可用
    //ui->loginBtn->setEnabled(false);//设置当前ui->loginBtn表示不可用
    //注册按钮发射一个点击的信号时，当前这个界面的槽函数就会执行
    //建立信号与槽：建立两个对象 的通信，一个对象发送一个信号，另一个对象的槽函数会被执行
    //connect(对象1, &对象1的类名::信号的函数名, 对象2, &对象2的类名::槽函数名字);
   // connect(ui->registerBtn,&QPushButton::clicked,this,&QMainWindow::close);
   // connect(ui->registerBtn,SIGNAL(clicked()),this,SLOT(close())); qt5之前的写法
    connect(ui->registerBtn,&QPushButton::clicked,this,&MainWindow::setLoginBtnEnbled);

    //自己发送和自己接收
    connect(this,&MainWindow::loginbtnenbled,this,&QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test()
{

}

void MainWindow::setLoginBtnEnbled()
{
    qDebug() << "------";
    // ui->loginBtn->setEnabled(true);

    //发送一个信号
    emit loginbtnenbled();
}
