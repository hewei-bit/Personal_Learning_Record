#include "readjson.h"
#include "ui_readjson.h"
#include "filminfo.h"
readJson::readJson(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::readJson)
{
    ui->setupUi(this);
}

readJson::~readJson()
{
    delete ui;
}

void readJson::on_pushButton_clicked()
{
    QFile file(":/film.json");
    bool isok = file.open(QIODevice::ReadOnly);
    qDebug() << "isok" << isok;
    if(isok)
    {
        QByteArray filmData = file.readAll();


//        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//        QString str = codec->toUnicode(filmData);
//        qDebug() << str;

        QJsonDocument doc = QJsonDocument::fromJson(filmData);
        QJsonObject object = doc.object();
        QJsonArray resultarray = object.value("result").toArray();

        QJsonObject gesila_info = resultarray.at(0).toObject();

        QListWidgetItem *item = new QListWidgetItem();
        filminfo *fmi = new filminfo(this);
        connect(fmi,&filminfo::send,fmi,&filminfo::showinfo);
        emit fmi->send(gesila_info);

        item->setSizeHint(QSize(715,215));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,fmi);

    }
    else {
        QMessageBox::warning(this,"警告","文件无法打开");
    }


}

