#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mTimer = new QTimer(this);

    //建立timeout信号的槽函数连接
   connect(mTimer,&QTimer::timeout,this,&MainWindow::countNumber);

   mTimer->setInterval(1000); //定时时间为1S,时间到，就是发送一个timeout信号
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
   mTimer->start();
}

void MainWindow::on_stopBtn_clicked()
{
   mTimer->stop();
}

void MainWindow::countNumber()
{
           static int i = ui->countLabel->text().toInt();
           i++;
           ui->countLabel->setText(QString::number(i));
}
