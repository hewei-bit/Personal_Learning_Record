#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_qualityBtn_clicked();
    void read_data(QNetworkReply* reply);
private:
    Ui::MainWindow *ui;
     QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H
