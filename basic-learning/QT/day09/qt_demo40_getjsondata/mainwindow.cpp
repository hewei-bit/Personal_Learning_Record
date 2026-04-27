 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QUrl>
#include <QTextCodec>
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

void MainWindow::on_getDataBtn_clicked()
{
    QUrl url("http://v.juhe.cn/historyWeather/province"
             "?=%E5%B9%BF%E4%B8%9C&key=b77b2977c2a8394c3591e661f085b867");
    QNetworkRequest request(url);
   manager->get(request);
}

void MainWindow::read_data(QNetworkReply *reply)
{
        QByteArray data =  reply->readAll();

        //因为从服务器返回来的数据中文它为UTF-8格式，但是，windows中qt它显示中文的格式
        //GB18030，如果默认直接输出服务器的数据，那么就相当于用GB18030来显示UTF-8的格式
        //数据，这样子，结果就可能显示不出来，要进行编码转换,QTextCodec

         // QTextCodec *codec = QTextCodec::codecForName("UTF-8");
         // QString string = codec->toUnicode(data);

         // qDebug() << "data = " << string;
          //[1] 将数据转换成QJsonDocment QJsonDocument::fromJson()
          //
         // static QJsonDocument  fromJson(const QByteArray &json, QJsonParseError *error = nullptr)
        QJsonDocument doc = QJsonDocument::fromJson(data);

        //[2] 要根据数据的格式来解析数据，首先判断数据的最外层是JSON对象还是JSON数组
        //如果是JSON对象，那么就通过QJsonDocument类中的成员函数object() --->  QJsonObject
        //如果是JSON数组，那么就通过QJsonDocument类中的成员函数array() ---> QJsonArray
       QJsonObject object = doc.object();

       //[3] 根据数据格式中的key-value中的key键来读取对应的值 key键为已知，value可能为不同类型的值
      QJsonArray array =  object.value("result").toArray(); //再根据数组的格式中值的类型来通过to方法进行转换
        //如果是数组的话，那通过at(i)方法，来遍历QJsonArray数组的元素
      for (int i=0;i<array.size();i++) {
          QJsonObject object1 = array.at(i).toObject();
         QString province = object1.value("province").toString();
         qDebug() << province;
         ui->listWidget->addItem(province);
      }
}
