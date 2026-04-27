#include "charserver.h"
#include "ui_charserver.h"
#include <QtDebug>
CharServer::CharServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharServer)
{
    ui->setupUi(this);

    connect(&server,&QTcpServer::newConnection,this,&CharServer::newClient);
}

CharServer::~CharServer()
{
    delete ui;
}

void CharServer::on_startBtn_clicked()
{
   quint16 port =  ui->portEdit->text().toUShort();
   //[1] 启动服务器
    server.listen(QHostAddress::Any,port);
}

void CharServer::on_clearBtn_clicked()
{
     ui->textEdit->clear();
}

void CharServer::on_sendBtn_clicked()
{
    QByteArray msg =  ui->textEdit->toPlainText().toUtf8();
     socket->write(msg);
}

void CharServer::newClient()
{
    socket =  server.nextPendingConnection();
   socket->write("hello");
    //建立readyRead信号 的槽函数
    connect(socket,&QTcpSocket::readyRead,this,&CharServer::readData);
}

void CharServer::readData()
{
//   QByteArray msg =  socket->readAll(); //error,有时候会掉线
    //首先要捕获信号的发送对象 ，找到到底是哪一个客户端发给信息到服务端
   QTcpSocket* msocket = dynamic_cast<QTcpSocket*>(sender());
   QString msg =  msocket->readAll();
   QString ip = msocket->peerAddress().toString();
    //"::ffff:192.168.73.2"
   ip = ip.remove(0,7);
   msg = ip + msg;
   msg = msg.append("\n");
   ui->listWidget->addItem(ip);
   ui->textBrowser->append(msg);
   qDebug() << "msg = " << msg << "ip = " << ip;
}
