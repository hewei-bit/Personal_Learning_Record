#include "mainwindow.h"
#include "ui_mainwindow.h"

LED::LED(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

LED::~LED()
{
    delete ui;
}
