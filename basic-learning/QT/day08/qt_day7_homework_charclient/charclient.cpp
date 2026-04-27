#include "charclient.h"
#include "ui_charclient.h"

CharClient::CharClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharClient)
{
    ui->setupUi(this);

    connect(&socket,&QTcpSocket::readyRead,this,&CharClient::readData);
}

CharClient::~CharClient()
{
    delete ui;
}

void CharClient::on_linkBtn_clicked()
{
     //[1] 连接服务器
    socket.connectToHost(ui->ipEdit->text(),ui->portEdit->text().toUShort());
}

void CharClient::on_clearBtn_clicked()
{
    ui->textEdit->clear();
}

void CharClient::on_sendBtn_clicked()
{
    socket.write(ui->textEdit->toPlainText().toUtf8());
}

void CharClient::readData()
{
     ui->textBrowser->setText(socket.readAll());
}
