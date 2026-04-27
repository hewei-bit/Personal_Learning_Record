#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建任务一
    MyTaskRunnable* mr = new MyTaskRunnable();

    //得到任务管理者
    QThreadPool * manager = QThreadPool::globalInstance();

    manager->start(mr);

    //创建任务二
    MyTaskRunnable* mr2 = new MyTaskRunnable();
     manager->start(mr2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
