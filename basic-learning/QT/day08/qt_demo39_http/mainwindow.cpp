#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QtDebug>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    //  void   finished(QNetworkReply *reply)
    qDebug() << manager->supportedSchemes();
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::read_data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_data(QNetworkReply *reply)
{
    qDebug() << " read_data";
    //QNetworkReply *reply 网络请求回应的对象，这个对象携带了服务器返回的数据
    //QIODevice ---- io设备
    QByteArray data =  reply->readAll();

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString string = codec->toUnicode(data);
    qDebug() << "reply data = " << string;
}

void MainWindow::on_requestBtn_clicked()
{
    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
    //QUrl url("http://fanyi.youdao.com/");
    QUrl url("https://pic.sogou.com/pics/home/detail_single.jsp"
             "?query=pexels&category=copyright_pc&mode=1#did=4&findex=undefined&groupId=null&query=");

    QNetworkRequest request(url);
    manager->get(request);
}
