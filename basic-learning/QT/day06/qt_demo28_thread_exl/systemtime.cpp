#include "systemtime.h"
#include "ui_systemtime.h"
#include <QTime>
SystemTime::SystemTime(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemTime)
{
    ui->setupUi(this);

     ui->systemTimeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
   //要在构造函数进行成员的初始化
    systemtimeth = new systemTimeThread(this);

    connect(systemtimeth,&systemTimeThread::systemtimeout,this,&SystemTime::updateSystemTime);
    systemtimeth->start();
}

SystemTime::~SystemTime()
{
    delete ui;
}

//每隔一秒钟，去通知该函数去获取系统时间
void SystemTime::updateSystemTime()
{
   ui->systemTimeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
}
