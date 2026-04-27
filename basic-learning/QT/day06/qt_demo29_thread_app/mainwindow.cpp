#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    systemtimeth = new systemTimeThread(this);
    connect(systemtimeth,&systemTimeThread::systemtimeout,
            this,&MainWindow::getSystemTime);
    connect(systemtimeth,&systemTimeThread::sendsystemtime,this,&MainWindow::updateSystemTime);
    systemtimeth->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getSystemTime(const QString &time)
{
    ui->timeLabel->setText(time);
}

void MainWindow::updateSystemTime(const QTime &time)
{
    ui->timeLabel->setText(time.toString("hh:mm:ss"));
}
