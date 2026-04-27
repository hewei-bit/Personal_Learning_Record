#include "filerecv.h"
#include "ui_filerecv.h"
#include <QHostAddress>
#include <QtDebug>
FileRecv::FileRecv(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileRecv)
{
    ui->setupUi(this);
    //建立客户端连接信号：newConnection
    connect(&mserver,&QTcpServer::newConnection,this,&FileRecv::new_client);
    //启动服务器
    mserver.listen(QHostAddress::Any,6666);
}

FileRecv::~FileRecv()
{
    delete ui;
}

void FileRecv::new_client()
{
   QTcpSocket* socket = mserver.nextPendingConnection();

   //建立客户端发送的数据的槽
   connect(socket,&QTcpSocket::readyRead,this,&FileRecv::read_data);
   filesize = 0;
   recvsize = 0;
}

void FileRecv::read_data()
{
    //接收端接收数据的顺序要跟发送端保持一致
    QTcpSocket* mscket = dynamic_cast<QTcpSocket*>(sender()) ;

    if(filesize == 0)
    {
        QByteArray array =  mscket->readAll(); //读取出来的是文件名字和文件大小

        //发送端是用QDataStream，那么接收端也要用QDataStream来实现
        QDataStream in(&array,QIODevice::ReadOnly);
        in >> filesize >> fileName;
        qDebug() << filesize << fileName;
        ui->progressBar->setMaximum(static_cast<int>(filesize));

        file.setFileName(fileName);
        file.open(QIODevice::WriteOnly);
    }

    //读文件内容

    if(recvsize < filesize)
    {
        QByteArray array = mscket->readAll();
        qDebug() << " recv content = " << array;

        file.write(array);

        recvsize += static_cast<quint64>( array.size());

        //更新传输进度
        ui->progressBar->setValue(static_cast<int>(recvsize));
    }

    if(recvsize == filesize)
    {
        file.close();
        //关闭当前的套接字
        mscket->disconnectFromHost();
    }
}
