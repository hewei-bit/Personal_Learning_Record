#ifndef SYSTEMTIMETHEAD_H
#define SYSTEMTIMETHEAD_H
#include <QThread>
#include <QTime>
//模拟下位机数据采集：数据采集到了---时间
class systemTimeThread : public QThread
{
    //自定义类中，为了支持信号和槽的操作 Q_OBJECT
     Q_OBJECT

 public:
     explicit systemTimeThread(QWidget *parent = nullptr)
     {

     }
     void run()override
     {
         while (1) {

           QThread::sleep(1);
           //emit systemtimeout(QTime::currentTime().toString("hh:mm:ss"));
           emit sendsystemtime(QTime::currentTime());
         }
     }
     ~systemTimeThread()override{}
 signals:
      void systemtimeout(const QString& data);
      void sendsystemtime(const QTime& data);

};

#endif // SYSTEMTIMETHEAD_H
