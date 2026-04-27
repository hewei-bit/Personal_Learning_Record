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
    //绑定端口号和ip
   QString IP =  ui->IP_lineEdit->text();
   quint16 port = ui->port_lineEdit->text().toUShort();
   socket.connectToHost(IP,port);

   this->isconnetion = true;
   ui->message_message_output->append(tr("与服务器连接成功：") + QDateTime::currentDateTime().toString("yyyy-M-dd hh:mm:ss"));

}

void MainWindow::on_send_Btn_clicked()
{
    //获取
    QString data = ui->message_input->text();
    socket.write(data.toUtf8());
    ui->message_message_output->append(data);   //将要发送的内容显示在listwidget
    ui->message_input->clear();
}

void MainWindow::on_clear_Btn_clicked()
{
    ui->message_message_output->clear();
}

void MainWindow::readData()
{
    QByteArray msg = socket.readAll();
    //有中文字符，转换编码方式
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString string = codec->toUnicode(msg);
    //获取时间 获得端口号  获得IP
    QDateTime datetime = QDateTime::currentDateTime();
    QString ip = socket.peerAddress().toString();
    int port = socket.peerPort();
    //将接收到的内容加入到kuang
    QString sendMessage = tr("recv from :") + ip + tr(" : ") \
                            + QString::number(port) + tr("   ") + datetime.toString("yyyy-M-dd hh:mm:ss") + tr("\n");
    sendMessage += string;
    ui->message_message_output->append(sendMessage);
    ui->IP_textBrowser->append(ip);
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::warning(this,"警告","与服务器断开连接",QMessageBox::Ok);
    socket.close();
    socket.deleteLater();
}
