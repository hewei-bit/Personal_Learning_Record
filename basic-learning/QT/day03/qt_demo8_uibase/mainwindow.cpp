#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化UI组件的状态
    initUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi()
{
        ui->stopBtn->setEnabled(false);
        ui->startBtn->setEnabled(true); //按钮的使能设置

        //对于一个特殊操作：一个开关的两种状态：开启，关闭
}

void MainWindow::on_startBtn_clicked()
{
      ui->startBtn->setText("停止");
      ui->stopBtn->setEnabled(true);
      ui->startBtn->setEnabled(false);
}

void MainWindow::on_stopBtn_clicked()
{
    ui->startBtn->setText("开始");
    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);
}
