#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUi();
}

 void MainWindow::initUi()
 {
     isState = false; //未操作
       ui->startBtn->setEnabled(true);
       ui->prevBtn->setEnabled(false);
       ui->pauseBtn->setEnabled(false);
       ui->stopBtn->setEnabled(false);
       ui->nextBtn->setEnabled(false);

 }
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked(bool checked)
{
     qDebug() << checked; //是否选中的意思，它是父类的属性，而不是QPushButton
     qDebug() << ui->startBtn->isCheckable();
     qDebug() << ui->startBtn->isChecked();

     ui->startBtn->setEnabled(false);
     ui->prevBtn->setEnabled(true);
     ui->pauseBtn->setEnabled(true);
     ui->stopBtn->setEnabled(true);
     ui->nextBtn->setEnabled(true);
}

void MainWindow::on_pauseBtn_clicked(bool checked)
{
     //一种开关两个状态的经典模型
     if(!isState)
     {
         ui->pauseBtn->setText("继续");
         isState = true;
     }else {
         ui->pauseBtn->setText("暂停");
         isState = false;
    }
}

void MainWindow::on_prevBtn_clicked()
{

}

void MainWindow::on_nextBtn_clicked()
{

}

void MainWindow::on_stopBtn_clicked()
{
    ui->startBtn->setEnabled(true);
    ui->prevBtn->setEnabled(false);
    ui->pauseBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    ui->nextBtn->setEnabled(false);
}
