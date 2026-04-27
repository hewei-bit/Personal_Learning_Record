#include "qdvwidget.h"
#include "ui_qdvwidget.h"
#include <QtDebug>

QdvWidget::QdvWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QdvWidget)
{
    ui->setupUi(this);

    wordIndex = 0;
    videoIndex = 0;
    //系统启动时，就要获取系统时间
    ui->timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));

    connect(&textTimer,&QTimer::timeout,this,&QdvWidget::word_auto);
    connect(&timeTimer,&QTimer::timeout,this,&QdvWidget::time_update);
    textTimer.start(3000);
    timeTimer.start(1000);
    //初始化视频列表
    videoFiles << "C:/GZ2027/QT录屏/qt数据库/DAY1/qttest.mp4"
               << "C:/GZ2027/QT录屏/qt数据库/DAY1/1数据库引入和数据库驱动类型.mp4"
               << "C:/GZ2027/QT录屏/qt数据库/DAY1/2sqlite数据库的操作.mp4";

    //初始化广告文字
    words << "AAAAA"<<"BBBBBB"<<"ccccc";

    //系统启动时，要就开始播放视频
    //创建一个播放的可选参数列表
     QStringList argments;
         //mpalyer -slave -quiet -wid 窗口ID号 媒体的路径
         argments << "-slave" << "-quiet" <<
                     "-wid" << QString::number(ui->videoLabel->winId())<<
                     videoFiles[videoIndex];
    mprocess.start("C:/GZ2027/mplayer-svn-38109/mplayer.exe",argments);

   // connect(&mprocess,&QProcess::finished,this,&QdvWidget::play_auto);

    //connect(&mprocess,&QProcess::finished,this,&QdvWidget::play_auto)

    connect(&mprocess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(play_auto()));


}

QdvWidget::~QdvWidget()
{
    delete ui;
}

void QdvWidget::play_auto()
{
      videoIndex++; //播放索引的值加1

      qDebug() << " 自动播放下一个视频";

      if(videoIndex < this->videoFiles.length())
      {
          QStringList argments;
              //mpalyer -slave -quiet -wid 窗口ID号 媒体的路径
              argments << "-slave" << "-quiet" <<
                          "-wid" << QString::number(ui->videoLabel->winId())<<
                          videoFiles[videoIndex];
         mprocess.start("C:/GZ2027/mplayer-svn-38109/mplayer.exe",argments);
      }

      if(videoIndex == this->videoFiles.length())
      {
          videoIndex = 0;
      }

}

void QdvWidget::word_auto()
{
  qDebug() <<"wordIndex " << wordIndex << " " << words.count();
    //获取字符串列表中数据
    //words.at(wordIndex++);
    ui->textLabel->setText(words.at(wordIndex++));
    if(wordIndex == words.count())
    {
        wordIndex = 0;
    }
}

void QdvWidget::time_update()
{
   ui->timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
}
