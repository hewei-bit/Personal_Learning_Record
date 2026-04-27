#ifndef SYSTEMTIMETHREAD_H
#define SYSTEMTIMETHREAD_H

#include <QThread>
class systemTimeThread :public QThread
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
          emit systemtimeout();
        }
    }
    ~systemTimeThread()override{}
signals:
    void systemtimeout();


};
#endif // SYSTEMTIMETHREAD_H
