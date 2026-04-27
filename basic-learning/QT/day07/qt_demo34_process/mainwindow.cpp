#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mprocess = new QProcess(this);

    //calcProcess = new QProcess(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_notepadBtn_clicked()
{
    // mprocess->start("notepad"); //一体式启动一个记事本程序
     //mprocess->startDetached("notepad"); //分离式启动
     if(mprocess->state() == QProcess::Running)
     {
         //关闭当前执行的额外进程
         mprocess->kill();//从字面上讲，马上就死，但实际上还是不会，要结合另一个函数
         mprocess->waitForFinished();
     }
     mprocess->start("notepad");
}

void MainWindow::on_calcBtn_clicked()
{
   //calcProcess->start("calc");
    if(mprocess->state() == QProcess::Running)
    {
        //关闭当前执行的额外进程
        mprocess->kill();//从字面上讲，马上就死，但实际上还是不会，要结合另一个函数
        mprocess->waitForFinished();
    }
    mprocess->start("calc");
}
