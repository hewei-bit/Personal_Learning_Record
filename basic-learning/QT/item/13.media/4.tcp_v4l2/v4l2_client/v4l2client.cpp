#include "v4l2client.h"
#include "ui_v4l2client.h"

v4l2client::v4l2client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::v4l2client)
{
    ui->setupUi(this);
    basize=0;
    socket=new QTcpSocket();
    connect(socket,SIGNAL(readyRead()),this,SLOT(read_data()));
}

v4l2client::~v4l2client()
{
    delete ui;
}
void v4l2client::read_data()
{
    QDataStream in(socket);
    QByteArray message;
    in.setVersion(QDataStream::Qt_5_6);

    if(basize==0)
    {
        if(socket->bytesAvailable()<(int)sizeof(quint64))
            return;
        in>>basize;
    }
    if(socket->bytesAvailable()<basize)
        return;
    in>>message;
    ShowImage(message);
}

void v4l2client::ShowImage(QByteArray ba)
{
    QString ss=QString::fromLatin1(ba.data(),ba.size());
    QByteArray rc;
    rc=QByteArray::fromBase64(ss.toLatin1());
    QByteArray rdc=qUncompress(rc);
    if(rdc.isEmpty())
        return;
    QImage img;
    img.loadFromData(rdc);

    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());
    update();
}

void v4l2client::on_pushButton_clicked()
{
    socket->connectToHost(ui->ip_edit->text(),ui->port_edit->text().toInt());
}
