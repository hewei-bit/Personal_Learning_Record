#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //[1] 监听客户端
    server.listen(QHostAddress::Any,6666);
    //[2]并且建立newConnection信号的槽连接
    connect(&server,&QTcpServer::newConnection,this,&MainWindow::newClient);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newClient()
{

     //[3] 查询到底是哪一个客户端进行连接 ---nextPendingConnection()
   QTcpSocket* socket =  server.nextPendingConnection();

   //可以给当前客户端回复消息
   socket->write("hello");

   //当客户端有信息--数据块到达时，会发送readyRead()，建立与该信号对应的槽函数

   connect(socket,&QTcpSocket::readyRead,this,&MainWindow::readData);

}

void MainWindow::readData()
{
    //判断哪底是哪一个发送者发来的消息
    QTcpSocket* mscoekt = dynamic_cast<QTcpSocket*>( sender()); //信息的发送者
    QByteArray msg = mscoekt->readAll();

     //对接收中文为UTF-8格式数据的编码处理，如果是英文信息，不需要增加
    /******************************************************/
      QTextCodec *codec = QTextCodec::codecForName("UTF-8");
      QString string = codec->toUnicode(msg);
      /************************************************/
    //并能获取对言信息
    QString ip = mscoekt->peerAddress().toString();

    qDebug() << "ip = " << ip << "msg = "<< string;
}
