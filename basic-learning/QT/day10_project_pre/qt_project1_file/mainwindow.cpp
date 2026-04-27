#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QFile file("./hello.txt"); //以build目录为当前目录
    QFile file("C:/Qt/qtWorkspace/qt_project1_file/text.txt");//绝对路径
    //Note: In WriteOnly or ReadWrite mode, if the relevant file does not already exist,
    //this function will try to create a new file before opening it.
   bool ok =  file.open(QIODevice::WriteOnly);//如果没有这个文件，先创建文件，再打开
   qDebug() << "ok = " << ok;

   file.write("hello");

}

MainWindow::~MainWindow()
{
    delete ui;
}
