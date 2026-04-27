#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //[2] 建立与信号readyRead的槽函数
    connect(&socket,&QTcpSocket::readyRead,this,&MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::readData()
{
   QByteArray msg =   socket.readAll();
    qDebug() << "msg = " << msg;
}
void MainWindow::on_sendBtn_clicked()
{
    QString data = ui->lineEdit->text();
     qDebug() << data;
    socket.write(data.toUtf8());
}

void MainWindow::on_linkBtn_clicked()
{
    //[1] 客户端向服务端发起请求
   socket.connectToHost("192.168.73.2",6666);
}
