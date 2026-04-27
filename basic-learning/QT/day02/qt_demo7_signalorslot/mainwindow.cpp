#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,&MainWindow::sendData,this,&MainWindow::btnClickedCount);
   // error: static assertion failed: The slot requires more arguments than the signal provides.
//#  define Q_STATIC_ASSERT_X(Condition, Message) static_assert(bool(Condition), Message)
      //在Qt中，信号和槽的参数规定，槽的参数个数不能比信号的参数多
    connect(ui->startBtn,&QPushButton::clicked,this,&MainWindow::btnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnClickedCount(int data)
{
    qDebug() << "void MainWindow::btnClickedCount(int data,QString s)";
     ui->countLabel->setText(QString::number(data));
}

void MainWindow::btnClicked()
{
    qDebug() << "void MainWindow::btnClicked()";
    static int i = 0;
    emit sendData(i); //发送信号时，可以携带数据给槽函数，也可以说对象1发送了数据给对象2
     i++;
}

void MainWindow::on_pushButton_clicked()
{

}
