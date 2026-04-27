#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <QMainWindow>
#include <QListWidgetItem>
#include <QProcess>
#include <QTime>
#include <QTimer>
#include <QRunnable>
#include <QtDebug>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include <QPen>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QMutex>
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

class runningTimer : public QMainWindow
{
    Q_OBJECT

public:
    explicit runningTimer(QWidget *parent = nullptr);
    ~runningTimer();

    void ad_vedio();

    void run_time();

    void ad_text();

    void paintEvent(QPaintEvent *);

    void http_weather();

    QString showText() const;

signals:
    void send_1();

private slots:
    void show_time();
    void show_ad_text();
    void read_data(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    QProcess ad_video_Process;
    QProcess ad_text_Process;
    QProcess ad_weather_Process;
    QProcess time_Process;

    QTimer *mtimer;
    QTimer *mtimer_1;


    int m_charWidth; //字符串宽度
    int m_curIndex;
    QString m_showText; //需要显示的字符串
    QString sl = {"广告位招租,有意致电166666666,曼联终将崛起！！！！"};

//    MyClock *cc;
    QNetworkAccessManager *manager;

    static int count;
};

static QMutex mutex;
class MyClock:public  QThread
{
    Q_OBJECT
public:
    explicit MyClock(QWidget *parent = nullptr){}
    ~MyClock(){}

    void run() override
    {
        while(1)
        {
            mutex.lock();
            QTime time_1 = QTime::currentTime();
            qDebug() << time_1.toString("hh:mm:ss");
            QThread::sleep(1);
            emit send();
            mutex.unlock();
        }
    }

signals:
    void send();
};
#endif // MAINWINDOW_H
