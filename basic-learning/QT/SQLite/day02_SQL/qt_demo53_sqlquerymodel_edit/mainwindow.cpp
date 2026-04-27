#include "mainwindow.h"
#include "ui_mainwindow.h"

runningTimer::runningTimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

runningTimer::~runningTimer()
{
    delete ui;
}
