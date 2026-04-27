#ifndef READJSON_H
#define READJSON_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QTextCodec>
#include <QListWidgetItem>
//JSON数据解析
#include<QJsonArray>  //[]
#include <QJsonDocument> //JSON文档 --- 将服务器数据转换成一个QJsonDocument
#include <QJsonObject> //{}
namespace Ui {
class readJson;
}

class readJson : public QMainWindow
{
    Q_OBJECT

public:
    explicit readJson(QWidget *parent = nullptr);
    ~readJson();

private slots:
    void on_pushButton_clicked();



private:
    Ui::readJson *ui;
};

#endif // READJSON_H
