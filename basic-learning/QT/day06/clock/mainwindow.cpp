#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    mtimer = new QTimer(this);
//    connect(mtimer,&QTimer::timeout,this,&MainWindow::clock);
//    mtimer->setInterval(1000);
//    mtimer->start(1000);
    //创建线程

    th = new Mythread(this);
    th->setObjectName("th");
    connect(th,&Mythread::send,this,&MainWindow::showtime);
    connect(th,&Mythread::send2,this,&MainWindow::showtime2);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::on_pushButton2_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clock()
{
    QTime time1 = QTime::currentTime();
    ui->label->setText(time1.toString("hh:mm:ss"));
    QDate data2 = QDate::currentDate();
    ui->label_2->setText(data2.toString("yyyy:MM:dd"));
}

void MainWindow::startclock()
{

}

void MainWindow::on_pushButton_clicked()
{
    th->start();
}

void MainWindow::on_pushButton2_clicked()
{
    th->terminate();
}

void MainWindow::showtime(QString time_str)
{

    ui->label->setText(time_str);
    qDebug()<<time_str;
    QDate data2 = QDate::currentDate();
    ui->label_2->setText(data2.toString("yyyy:MM:dd"));
}

void MainWindow::showtime2()
{
    QTime time = QTime::currentTime();
    ui->label->setText(time.toString("hh:mm:ss"));
    QDate data2 = QDate::currentDate();
    ui->label_2->setText(data2.toString("yyyy:MM:dd"));
}
