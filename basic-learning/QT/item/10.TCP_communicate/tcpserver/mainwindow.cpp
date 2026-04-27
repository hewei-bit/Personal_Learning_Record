#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TCP服务器");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newClient()
{
    //查询是哪一个客户端连接
    socket = server.nextPendingConnection();
    //收到及回复
    socket->write("hello");
    //当客户端有信息，会发送readyRead(),建立与该信号对应的槽函数
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::readData);

}
void MainWindow::readData()
{
    QByteArray array = socket->readAll();    //接收消息
    qDebug() << "msg = " << array;
    //有中文字符，转换编码方式
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString string = codec->toUnicode(array);
    qDebug() << "msg = " << string;
    //获取时间
    QDateTime datetime = QDateTime::currentDateTime();
    //读取消息
    QHostAddress clientaddr = socket->peerAddress(); //获得IP
    int port = socket->peerPort();   //获得端口号
    QString sendMessage = tr("recv from :") + clientaddr.toString() + tr(" : ") \
                            + QString::number(port) + tr("   ") + datetime.toString("yyyy-M-dd hh:mm:ss") + tr("\n");
    sendMessage += string;
    //将接收到的内容加入到kuang
    ui->message_message_output->append(sendMessage);

    ui->IP_textBrowser->setText(clientaddr.toString());

}
void MainWindow::on_start_Btn_clicked()
{
    int port = ui->port_lineEdit->text().toInt();
    //监听客户端
    server.listen(QHostAddress::Any,port);
    //建立连接
    connect(&server,&QTcpServer::newConnection,this,&MainWindow::newClient);
    qDebug() << "server start";
}

void MainWindow::on_send_Btn_clicked()
{

    //获取单行文本框内要发送的内容
    QString sendmessage = ui->message_input->text();
    qDebug() <<"send = " <<sendmessage;

    if(!sendmessage.isEmpty()) //确保有客户端连接，并且发送内容不为空
    {
        //发送消息到客户端
        socket->write(sendmessage.toUtf8());
        QString localDispalyMessage = "send to client: " + sendmessage \
                        + QDateTime::currentDateTime().toString(" yyyy-M-dd hh:mm:ss") + tr("\n");
        ui->message_message_output->append(localDispalyMessage);   //将要发送的内容显示在listwidget
    }

    ui->message_input->clear();
}

void MainWindow::on_clear_Btn_clicked()
{
    ui->message_message_output->clear();
}

void MainWindow::on_pushButton_clicked()
{
    if(socket != nullptr)
    {
        ui->message_message_output->append("client logout!");
        socket->close();
        socket->deleteLater();
    }
}
