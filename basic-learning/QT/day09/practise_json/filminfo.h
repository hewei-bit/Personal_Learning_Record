#ifndef FILMINFO_H
#define FILMINFO_H

#include <QMainWindow>
#include <QListWidget>
//JSON数据解析
#include<QJsonArray>  //[]
#include <QJsonDocument> //JSON文档 --- 将服务器数据转换成一个QJsonDocument
#include <QJsonObject> //{}
namespace Ui {
class filminfo;
}

class filminfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit filminfo(QWidget *parent = nullptr);
    ~filminfo();
signals:
    void send(QJsonObject film_info);
public slots:
    void showinfo(QJsonObject film_info);

private:
    Ui::filminfo *ui;
};

#endif // FILMINFO_H
