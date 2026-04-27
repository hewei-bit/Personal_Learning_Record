#include "filesend.h"
#include "ui_filesend.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QtDebug>

FileSend::FileSend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileSend)
{
    ui->setupUi(this);

    //当客户端连接成功时，才考虑发送文件，在连接成功时，会发送一个信号：connected,
    //如果掉线时，会发送disconnect
    connect(&mscoket,&QTcpSocket::connected,this,&FileSend::send_file_head);
    connect(&mscoket,&QTcpSocket::bytesWritten,this,&FileSend::send_file_text);
}

FileSend::~FileSend()
{
    delete ui;
}

void FileSend::on_sendBtn_clicked()
{
   mscoket.connectToHost(ui->ipEdit->text(),ui->portEdit->text().toUShort());
   filesize = 0;
   sendsize = 0;
}

void FileSend::on_selectBtn_clicked()
{
    //添加要发送的文件
    QString filePath = QFileDialog::getOpenFileName(this);
    ui->fileEdit->setText(filePath);
}

//发送文件头
void FileSend::send_file_head()
{
    //创建文件信息对象
    QFileInfo info(ui->fileEdit->text());
    fileName = info.fileName();
    filesize = info.size();
    qDebug() << filesize;
    //QFile write read --- QDataStream进行文件的读写
    QByteArray array;
    //将文件的头信息通过QDataStream来写入到QByteArray中
    QDataStream out(&array,QIODevice::WriteOnly);
    out << filesize << fileName;
    ui->progressBar->setMaximum(static_cast<int>(filesize));
    mscoket.write(array); //将文件头信息发送到网络中
    //将文件相关的信息转换成一个文件的对象 ---为发送文件数据做准备
    file.setFileName(ui->fileEdit->text());
    file.open(QIODevice::ReadOnly);
}

void FileSend::send_file_text()
{
    if(sendsize < filesize)
    {
        QByteArray array = file.read(1024*10); //每次从文件中读取10K
        //再利用网络来传输数据
        mscoket.write(array);

        sendsize += array.size();
        qDebug() << sendsize;
        ui->progressBar->setValue(static_cast<int>(sendsize));
    }
    if(sendsize == filesize)
    {
        file.close();
    }

}
