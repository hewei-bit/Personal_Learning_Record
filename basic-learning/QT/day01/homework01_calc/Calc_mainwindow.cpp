#include "calc_mainwindow.h"
#include "ui_calc_mainwindow.h"
#include <QtDebug>

Calc_MainWindow::Calc_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calc_MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("计算器");

//    qDebug() << ui->pushButton_0->isEnabled();
    ui->pushButton_0->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_0->setEnabled(true);

//    connect(ui->pushButton_1,&QPushButton::clicked,this,&Calc_MainWindow::close);
//    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Calc_MainWindow::setLoginBtnEnabled);
    //自己发送和自己接收
    connect(this,&Calc_MainWindow::loginbtnenabled,this,&QMainWindow::close);
}

Calc_MainWindow::~Calc_MainWindow()
{
    delete ui;
}

void Calc_MainWindow::setLoginBtnEnabled()
{
    qDebug() << "------";
    ui->pushButton_2->setEnabled(true);
    emit loginbtnenabled();
}
