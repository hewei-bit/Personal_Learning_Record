#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    w1 = new WorkThread1();
    w2 = new WorkThread2();

    w1->start();
    w2->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
