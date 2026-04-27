#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建线程池
    QThreadPool *manager = QThreadPool::globalInstance();
    //创建任务一
    MytaskRunable* mr = new MytaskRunable();
    //创建任务二
    MytaskRunable* mr2 = new MytaskRunable();
    //加入线程池并启动
    manager->start(mr);
    manager->start(mr2);

    connect(mr,&MytaskRunable::run,this,&MainWindow::showdata);
//    connect(mr2,&MytaskRunable::run,this,&MainWindow::showdata);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::showdata(const QString &data)
{
    ui->label->setText(data);
}
