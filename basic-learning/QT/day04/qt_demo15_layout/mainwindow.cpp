#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
#if 0
    //[1] 创建一个窗口对象
    QWidget *w = new QWidget(this); //给QMainWindow设置一个QWidget，对于QMainWindow
           w->resize(this->width(),this->height());                         //相当于QMainWindow框架中的central QWidget

    //[2]给窗口设置一个布局
    QVBoxLayout* bl = new QVBoxLayout;
   //[3] 在布局中增加组件
    QPushButton* btn1 = new QPushButton("button1",w);
     QPushButton* btn2 = new QPushButton("button2",w);

    btn1->setMaximumSize(200,200);
    btn1->setMinimumSize(200,200);
    //还可以设置关于组件的其他属性的值：尺寸策略，样式，等
    bl->addWidget(btn1); //给一个布局添加一个组件
    bl->addWidget(btn2);
    //[4]关联窗口跟布局
    w->setLayout(bl); //给一个窗口设置一个布局
#endif
    //[1] 创建一个窗口对象
    QWidget *w = new QWidget(this); //给QMainWindow设置一个QWidget，对于QMainWindow
           w->resize(this->width(),this->height());                         //相当于QMainWindow框架中的central QWidget

    //[2]给窗口设置一个布局
    QHBoxLayout* bl = new QHBoxLayout;
   //[3] 在布局中增加组件
    QPushButton* btn1 = new QPushButton("button1",w);
     QPushButton* btn2 = new QPushButton("button2",w);

    btn1->setMaximumSize(200,200);
    btn1->setMinimumSize(200,200);
    //还可以设置关于组件的其他属性的值：尺寸策略，样式，等
    bl->addWidget(btn1); //给一个布局添加一个组件
    bl->addWidget(btn2);
    bl->setStretchFactor(btn1,3);
    //[4]关联窗口跟布局
    w->setLayout(bl); //给一个窗口设置一个布局

}

MainWindow::~MainWindow()
{
    delete ui;
}
