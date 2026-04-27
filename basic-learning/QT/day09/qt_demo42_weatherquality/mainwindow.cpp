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

void MainWindow::read_data(QNetworkReply* relpy)
{

     QByteArray array = relpy->readAll();

     QJsonDocument doc = QJsonDocument::fromJson(array);

     //
     QJsonObject object =  doc.object();
     QJsonArray resultArray =  object.value("result").toArray();
     QJsonObject arrayObject =  resultArray.at(0).toObject();

     QJsonObject citynowObject = arrayObject.value("citynow").toObject();
     /*
                "city":"广州",
                "AQI":"36",
                "quality":"优",
                "date":"2020-07-10 14:00"
     */

     QString city = citynowObject.value("city").toString();
     QString AQI =  citynowObject.value("AQI").toString();
     QString quality = citynowObject.value("quality").toString();
     QString date = citynowObject.value("date").toString();

     ui->cityLabel->setText(city);
     ui->AQILabel->setText(AQI);
     ui->qualityLabel->setText(quality);
     ui->dateLabel->setText(date);
}

void MainWindow::on_qualityBtn_clicked()
{
    QUrl url("http://web.juhe.cn:8080/environment/air/cityair?"
             "city=%E5%B9%BF%E5%B7%9E&key=176ba257c52f609ae228e8c47a90dac3");
    QNetworkRequest request(url);
   manager->get(request);
}
