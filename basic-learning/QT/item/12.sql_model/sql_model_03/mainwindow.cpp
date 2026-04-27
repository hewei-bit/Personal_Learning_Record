#include "mainwindow.h"
#include "ui_mainwindow.h"

running_Timer::running_Timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

running_Timer::~running_Timer()
{
    delete ui;
}
