#include "mainwindow.h"
#include "ui_mainwindow.h"

int runningTimer::count = 0;


void runningTimer::ad_vedio()
{
    if(ad_video_Process.state() == QProcess::Running)
    {
        ad_video_Process.kill();
        ad_video_Process.waitForFinished();
    }

    QString cmd = QString("mplayer -slave -quiet "
                          "-geometry 0:0 -zoom -x %1 -y %2 "
                          "/zero/qttest.mp4")
            .arg(ui->ad_vediolabel->width())
            .arg(ui->ad_vediolabel->height());
    qDebug() << "cmd = " << cmd;

    ad_video_Process.start(cmd);
}

void runningTimer::show_time()
{
    QTime time = QTime::currentTime();
    ui->time_label->setText(time.toString("hh:mm:ss"));
    QDate date = QDate::currentDate();
    ui->date_label->setText(date.toString("yyyy-MM-dd"));
}

void runningTimer::show_ad_text()
{
//    update();
//    m_curIndex++;
//    if (m_curIndex*m_charWidth > width())
//        m_curIndex = 0;
    // 当截取的位置比字符串长时，从头开始
    if (count > sl.length())
        count = 0;

    ui->ad_text_label->setText(sl.mid(count));

// 闪动文字
//    ui->ad_text_label->setText(sl[count%3]);
    count++;
}

void runningTimer::read_data(QNetworkReply* reply)
{
    QByteArray array = reply->readAll();
    qDebug() << array;
    QJsonDocument doc = QJsonDocument::fromJson(array);

    //
    QJsonObject object =  doc.object();
    QString reason = object.value("reason").toString();
    qDebug() << reason;
    QJsonObject resultObject = object.value("result").toObject();
//    QJsonObject todayObject = resultObject.value("today").toObject();

    QString mcity = resultObject.value("city").toString();
    qDebug() << mcity;
    QJsonObject realtimeObject = resultObject.value("realtime").toObject();
    QString mtemperature = realtimeObject.value("temperature").toString();
    QString minfo = realtimeObject.value("info").toString();
    qDebug() << minfo;
    qDebug() << mtemperature;
    /*
{
    "reason":"查询成功!",
    "result":{
        "city":"广州",
        "realtime":{
            "temperature":"29",
            "humidity":"75",
            "info":"多云",
            "wid":"01",
            "direct":"东南风",
            "power":"2级",
            "aqi":"15"
        }}
    */


    ui->address_label->setText(mcity);
    ui->weather_label->setText(minfo);
    ui->tempreaturelabel->setText(mtemperature);
}

QString runningTimer::showText() const
{
    return m_showText;
}

void runningTimer::run_time()
{
    mtimer = new QTimer(this);
    connect(mtimer,&QTimer::timeout,this,&runningTimer::show_time);
    mtimer->setInterval(1000);
    mtimer->start(1000);
}

void runningTimer::ad_text()
{
    m_curIndex = 0;//当前文字下标值
    m_showText = tr("Welcome to the image processing software of Star Dragon Company");//显示的文字
    m_charWidth = fontMetrics().width("a");//每个字符的宽度

    mtimer = new QTimer(this);
    connect(mtimer,&QTimer::timeout,this,&runningTimer::show_ad_text);
    mtimer->setInterval(1000);
    mtimer->start(1000);
}

void runningTimer::paintEvent(QPaintEvent *)
{
    QPen pen;
    pen.setColor(QColor(255,0,255));

    pen.setStyle(Qt::DashDotDotLine);

    QFont font("楷体",14,QFont::Bold);


    QPainter painter(this);
    painter.setPen(pen);

    painter.setFont(font);
    painter.drawText(0, 15, m_showText.mid(m_curIndex));
    painter.drawText(width() - m_charWidth*m_curIndex, 15, m_showText.left(m_curIndex));
}

void runningTimer::http_weather()
{
    manager = new QNetworkAccessManager();

    connect(manager,&QNetworkAccessManager::finished,this,&runningTimer::read_data);

    QUrl url("http://apis.juhe.cn/simpleWeather/query?"
             "city=%E5%B9%BF%E5%B7%9E"
             "&key=6eaaa433d136ff59653d126c67270943");
    QNetworkRequest request(url);
    manager->get(request);
}

runningTimer::runningTimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //播放视频广告
    ad_vedio();

    //显示时间
//    run_time();

//    //创建线程池
//    QThreadPool *manager = QThreadPool::globalInstance();
//    //创建任务一
//    MyClock* mc = new MyClock();
//    //加入线程池并启动
//    manager->start(mc);
//    connect(mc,&MyClock::run,this,&MainWindow::show_time);


    MyClock* mc = new MyClock();
    mc->setObjectName("mc");
    connect(mc,&MyClock::send,this,&runningTimer::show_time);
    mc->start();


    //显示广告标语
    ad_text();

    // 天气API已连接成功
    http_weather();
    QImage img;
    img.load(":/new/prefix1/weather/sunny.png");
    QPixmap originalPixmap = QPixmap::fromImage(img);
    ui->label->setPixmap(originalPixmap.scaled(ui->label->size(),
                         Qt::IgnoreAspectRatio,
                         Qt::SmoothTransformation));


}

runningTimer::~runningTimer()
{
    delete ui;
}


