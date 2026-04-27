#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化属性的值
    ui->progressBar->setMaximum(500);
    ui->progressBar->setValue(150);
    ui->progressBar->setMinimum(0);

    ui->horizontalSlider->setMaximum(500);
   qDebug() << ui->progressBar->value(); //获取当前进度的值
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    qDebug() << position;
    ui->progressBar->setValue(position);
}
