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
    manager = QThreadPool::globalInstance();

    manager->start(mr);

    connect(mr,&MyTaskRunnable::sendData,this,&MainWindow::updateUI);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete  manager;
}

void MainWindow::updateUI(const QString &data)
{
    ui->label->setText(data);
}
