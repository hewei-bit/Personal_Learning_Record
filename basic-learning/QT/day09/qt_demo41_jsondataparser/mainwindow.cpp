#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
       picmanager = new QNetworkAccessManager();
    //请求完成时，会发送一个finished信号
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::read_data);

    connect(picmanager,&QNetworkAccessManager::finished,this,&MainWindow::read_picdata);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuBtn_clicked()
{
    QUrl url("http://apis.juhe.cn/cook/query.php?"
             "menu=%E7%99%BD%E5%88%87%E9%B8%A1&dtype=&pn=&rn=&key=fc93060a8d4e6ec156d5eb013130fb7f");
    QNetworkRequest request(url);
   manager->get(request);
}

void MainWindow::read_data(QNetworkReply *reply)
{
        QByteArray data =  reply->readAll();

      //[1] 将数据转换成QJsonDocument
        QJsonDocument doc = QJsonDocument::fromJson(data);

        //[2] 最外层是一个json对象
        QJsonObject object = doc.object();

      QJsonObject resultobject = object.value("result").toObject();

     QJsonArray dataarray =   resultobject.value("data").toArray();

        QJsonObject menuobject =  dataarray.at(0).toObject();
        //获取图片
       QJsonArray albumsarray =  menuobject.value("albums").toArray();
       QString albums =  albumsarray.at(0).toString();
       qDebug() << "albums = " << albums;
       QUrl url(albums);
        QNetworkRequest request(url);
       picmanager->get(request);

       QJsonArray stepsarray = menuobject.value("steps").toArray();
       for (int i=0;i<stepsarray.size();i++) {
          QJsonObject stepobject =  stepsarray.at(i).toObject();
         QString step =  stepobject.value("step").toString();
         step = step + "\n";
         ui->textBrowser->append(step);
       }

}

void MainWindow::read_picdata(QNetworkReply *reply)
{

    QByteArray picdata =   reply->readAll();
qDebug() << picdata;
    QPixmap map;
   bool ok =  map.loadFromData(picdata);
qDebug() << ok;
     ui->piclabel->setPixmap(map);

}
