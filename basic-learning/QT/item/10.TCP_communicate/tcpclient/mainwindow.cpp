#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /***    初始化TCP   ***/
    this->setWindowTitle("TCP客户端");
    this->isconnetion = false;

    //终止之前的连接，重置套接字
    socket.abort();
    //建立与信号readyRead的槽函数
    connect(&socket,&QTcpSocket::readyRead,this,&MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_Btn_clicked()
{
    //[1] 客户端向服务端发起请求
   QString IP =  ui->IP_lineEdit->text();
   int port = ui->port_lineEdit->text().toInt();
   socket.connectToHost(IP,port);

   this->isconnetion = true;
   ui->message_message_output->append(tr("与服务器连接成功：") + QDateTime::currentDateTime().toString("yyyy-M-dd hh:mm:ss"));

}

void MainWindow::on_send_Btn_clicked()
{
    QString data = ui->message_input->text();
    qDebug()<<data;
    QString data_new = "client:"+data;
    socket.write(data_new.toUtf8());
    ui->message_message_output->append(data_new);   //将要发送的内容显示在listwidget
    ui->message_input->clear();
}

void MainWindow::on_clear_Btn_clicked()
{
    ui->message_message_output->clear();
}

void MainWindow::readData()
{

    QByteArray msg = socket.readAll();
    qDebug() << "msg = " << msg;
    //有中文字符，转换编码方式
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString string = codec->toUnicode(msg);
    qDebug() << "msg = " << string;
    //获取时间
    QDateTime datetime = QDateTime::currentDateTime();
    //读取消息
    QHostAddress clientaddr = socket.peerAddress(); //获得IP
    int port = socket.peerPort();   //获得端口号
    QString sendMessage = tr("recv from :") + clientaddr.toString() + tr(" : ") \
                            + QString::number(port) + tr("   ") + datetime.toString("yyyy-M-dd hh:mm:ss") + tr("\n");
    sendMessage += string;
    //将接收到的内容加入到kuang
    ui->message_message_output->append(sendMessage);

    //判断到底是哪个发送者发来的消息
    QTcpSocket* msocket = dynamic_cast<QTcpSocket *>(sender());
    //获取对方信息
    QString ip = msocket->peerAddress().toString();
    ui->IP_textBrowser->setText(ip);
    qDebug() << ip << string;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::warning(this,"警告","与服务器断开连接",QMessageBox::Ok);
    socket.close();
    socket.deleteLater();
}
