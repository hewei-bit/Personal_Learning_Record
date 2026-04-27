#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cmdprocess = new QProcess(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //设置启动进程
    cmdprocess->setProgram("cmd");
    //获取键入命令行的命令
    QStringList argument;
    argument<<"/c"<<ui->lineEdit->text();
    cmdprocess->setArguments(argument);
    //启动cmd
    cmdprocess->start();
    //等待程序启动
    cmdprocess->waitForStarted();
    //等待程序关闭
    cmdprocess->waitForFinished();
    //获取程序输出信息
    QString result = QString::fromLocal8Bit(cmdprocess->readAllStandardOutput());
    ui->show_textBrowser->setText(result);
}
