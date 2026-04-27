#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    th = new MyThread(this);
    th->setObjectName("th");

    //当线程启动后，会发送started信号
   connect(th,&MyThread::started,this,&MainWindow::startThreadWork);

   th2 = new MyThread(this);
   th2->setObjectName("th2");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    th->start();
    th2->start();
    th->setPriority(QThread::HighPriority);
}

void MainWindow::startThreadWork()
{
    qDebug() << "startThreadWork";
}
