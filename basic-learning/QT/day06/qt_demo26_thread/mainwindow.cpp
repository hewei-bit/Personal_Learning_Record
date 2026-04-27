#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    th = new MyThread(this);
    th->setObjectName("th");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startThreadBtn_clicked()
{
      //线程要启动后，才会去执行run函数
    th->start();
}

void MainWindow::on_stopThreadBtn_clicked()
{
   th->terminate(); //停止一个线程


}
