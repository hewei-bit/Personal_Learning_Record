#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
    //请求完成时，会发送一个finished信号
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::read_data);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_locateBtn_clicked()
{
    QUrl url("http://v.juhe.cn/offset/index"
             "?lng=123&lat=213&type=2&dtype=&callback=&key=fb582107caa10647ebdfee92c4fb6e0f");
    QNetworkRequest request(url);
    //发送请求，如果成果出发read_data
    manager->get(request);
}

void MainWindow::read_data(QNetworkReply* reply)
{
    QByteArray data = reply->readAll();
    qDebug() << data;
    QJsonDocument doc = QJsonDocument::fromJson(data);

    QJsonObject object = doc.object();

    QString resultCode = object.value("resultcode").toString();
    qDebug() << resultCode;

    QJsonObject result_object = object.value("result").toObject();

    QString lng = result_object.value("lng").toString();
    qDebug() <<"lng : " <<lng;
    QString lng_str = "lng : "+lng;
    ui->local_textBrowser->append("lng : "+lng);

    QString lat = result_object.value("lat").toString();
    ui->local_textBrowser->append("lat : "+lat);

    QString off_lng = result_object.value("off_lng").toString();
    ui->local_textBrowser->append("off_lng : "+off_lng);

    QString off_lat = result_object.value("lng").toString();
    ui->local_textBrowser->append("off_lat : "+off_lat);

}









