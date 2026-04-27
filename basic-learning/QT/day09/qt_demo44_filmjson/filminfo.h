#ifndef FILMINFO_H
#define FILMINFO_H

#include <QMainWindow>
//完成对网络数据的请求
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

//JSON数据解析
#include<QJsonArray>  //[]
#include <QJsonDocument> //JSON文档 --- 将服务器数据转换成一个QJsonDocument
#include <QJsonObject> //{}

namespace Ui {
class FilmInfo;
}

class FilmInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilmInfo(QWidget *parent = nullptr);
    ~FilmInfo();

private slots:
    void on_findFilmBtn_clicked();
    void getFilmPic(QNetworkReply* reply);
signals:
    void sendPicData(const QByteArray& data);
private:
    Ui::FilmInfo *ui;
    QNetworkAccessManager *manager;
};

#endif // FILMINFO_H
