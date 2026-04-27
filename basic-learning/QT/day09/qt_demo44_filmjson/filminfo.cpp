#include "filminfo.h"
#include "ui_filminfo.h"
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QTextCodec>
#include <QListWidgetItem>
#include "itemform.h"

FilmInfo::FilmInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilmInfo)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();

    //请求完成时，会发送一个finished信号
    connect(manager,&QNetworkAccessManager::finished,this,&FilmInfo::getFilmPic);
}

FilmInfo::~FilmInfo()
{
    delete ui;
}
/*
{
    "resultcode": "200",
    "reason": "成功的返回",
    "result": [
        {
            "movieid": "10641",
            "rating": "7.3",
            "genres": "动作/惊悚/科幻",
            "runtime": "139 min",
            "language": "英语/法语/日语",
            "title": "哥斯拉",
            "poster": "http://v.juhe.cn/movie/img?5146",
            "writers": "迪安·德夫林,罗兰·艾默里奇,...",
            "film_locations": "美国",
            "directors": "罗兰·艾默里奇",
            "rating_count": "3191",
            "actors": "马修·布罗德里克 Matthew Broderick,让·雷诺 Jean Reno,玛丽亚·皮提罗 Maria Pitillo,汉克·阿扎利亚 Hank Azaria",
            "plot_simple": "一道亮光划过天际，太平洋上波涛汹涌，海浪以不可思议的速度将一架货机卷入海里；巴哈马丛林中，出现了巨大的脚印；一股神秘的力量一直朝纽约而来，这座人口稠密的都市即将受到这个怪兽“哥斯拉”的袭击。“哥斯拉”是因为核试验造成气..",
            "year": "1998",
            "country": "美国",
            "type": "null",
            "release_date": "19980518",
            "also_known_as": "酷斯拉,怪兽哥斯拉"
        },
        {
        }
}
*/

void FilmInfo::on_findFilmBtn_clicked()
{
    QFile file(":/film.json");

    //对于RES目录 下的资源文件，只能读取，不要进行写操作，打开文件并读取
    bool isok = file.open(QIODevice::ReadOnly);
    qDebug() << "isok = " << isok;
    if(isok)
    {
          QByteArray filmData = file.readAll();
//        /*   QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//           QString string = codec->toUnicode(filmData);

//           qDebug() << "data = " << string;*/

           QJsonDocument doc = QJsonDocument::fromJson(filmData);

           QJsonObject object =  doc.object();

           QJsonArray resultArray =  object.value("result").toArray();

           for (int i=0;i<resultArray.size();i++) {
              QJsonObject objectArray= resultArray.at(i).toObject();

              QString rating = objectArray.value("rating").toString();
              QString genres = objectArray.value("genres").toString();
              QString runtime = objectArray.value("runtime").toString();
              QString language = objectArray.value("language").toString();
              QString title = objectArray.value("title").toString();
              QString poster = objectArray.value("poster").toString();
              QString year = objectArray.value("year").toString();

              QString country = objectArray.value("country").toString();
              QString directors = objectArray.value("directors").toString();
              QString rating_count = objectArray.value("rating_count").toString();
              QString actors = objectArray.value("actors").toString();


              QUrl url(poster);
              QNetworkRequest request(url);
               manager->get(request);
              qDebug() << rating << genres << runtime;
              QListWidgetItem * item = new QListWidgetItem;
              ItemForm* itemform = new ItemForm();


              itemform->setFilmInfo(rating,genres,runtime
                                    ,language,title,
                                    year,country,directors,
                                    rating_count,
                                    actors);

              item->setSizeHint(QSize(799,317));
               ui->listWidget->addItem(item);

               ui->listWidget->setItemWidget(item,itemform);

               connect(this,&FilmInfo::sendPicData,itemform,&ItemForm::getPicData);

           }



    }else {
        QMessageBox::information(this,"打开提示","文件路径或者文件名字错误，请重试");
    }
}

void FilmInfo::getFilmPic(QNetworkReply *reply)
{
      QByteArray array =  reply->readAll();

      emit sendPicData(array);

}
