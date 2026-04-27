#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->setWindowTitle(QString::fromStdString("文件发送客户端"));

    //客户端连接成功，才考虑发送文件，连接成功时，会发送一个信号：connected,
    //如果掉线时会发送disconnect
    connect(&msocket,&QTcpSocket::connected,this,&MainWindow::send_file_head);
    connect(&msocket,&QTcpSocket::bytesWritten,this,&MainWindow::send_file_text);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendBtn_clicked()
{
    msocket.connectToHost(ui->ipEdit->text(),ui->portEdit->text().toUShort());
    filesize = 0;
    sendsize= 0;
}

void MainWindow::on_selectBtn_clicked()
{
    //选择被传输的文件
    QString filepath = QFileDialog::getOpenFileName(this);
    ui->fileEdit->setText(filepath);
}
//发送文件头
void MainWindow::send_file_head()
{
    //创建文件信息对象
    QFileInfo info(ui->fileEdit->text());
    fileName = info.fileName();
    filesize = info.size();
    qDebug() << filesize;
    //QFile write read  --- QDataStream进行文件读写
    QByteArray array;
    //将文件的头信息通过QDataStream来写入到QByteArray中
    QDataStream out(&array,QIODevice::WriteOnly);
    out << filesize <<fileName;
    ui->progressBar->setMaximum(static_cast<int>(filesize));
    msocket.write(array); //将文件头信息发送到网络中
    //将文件的相关信息转换成一个文件对象，为发送文件做准备
    file.setFileName(ui->fileEdit->text());
    file.open(QIODevice::ReadOnly);
}

void MainWindow::send_file_text()
{
    if(sendsize < filesize)
    {
        //每次从文件读1024字节
        QByteArray array = file.read(1024);
        //再利用网络进行传输
        msocket.write(array);
        sendsize+=array.size();
        qDebug()<<sendsize;
        ui->progressBar->setValue(static_cast<int>(sendsize));
    }
    if(sendsize == filesize)
    {
        file.close();
    }
}
