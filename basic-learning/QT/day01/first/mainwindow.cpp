#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // ui->setupUi(this);


   // QLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())

  //  QLabel(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
   //在this这个对象的界面 上，显示一个文本
   // QLabel *label = new QLabel("第一个文本",this); //this --->MainWindow(界面)
    //构造函数中初始化成员变量
    label = new QLabel(this);
    label->setText("第一个文本");

    label1 = new QLabel(this);
    label1->setText("另外的文本"); //窗口的坐标系统在左上角(0,0)
    //可以通过位置函数来设置组件显示的位置
    label1->setGeometry(0,label->height(),label1->width(),label1->height());


     Test();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete label;
    delete label1;
}

void MainWindow::Test()
{
   label->setText("修改内容");
}
