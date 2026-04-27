#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QtDebug>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //方式一 使用构造函数
    QTime time(0,0,0);

    qDebug() << time.toString("hh:mm:ss");
    //方式二 使用静态函数
   // [static] QTime QTime::currentTime()
    QTime time1 = QTime::currentTime(); //获得当前本地系统时间
     qDebug() << time1.toString("hh:mm:ss");
     ui->timeLabel->setText(time1.toString("hh:mm:ss"));
     QDate date = QDate::currentDate();
     qDebug() << date.toString("yyyy/MM/dd");
     ui->dateLabel->setText(date.toString("yyyy/MM/dd"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
