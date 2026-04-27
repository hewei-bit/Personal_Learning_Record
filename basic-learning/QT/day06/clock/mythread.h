#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QMainWindow>
#include "QTime"
#include <QThread>
#include <QtDebug>
#include "QTime"

class Mythread:public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QWidget *parent = nullptr)
    {}
    ~Mythread(){}

    void run() override
    {
        while(1)
        {
            QTime time1 = QTime::currentTime();
            qDebug() << time1.toString("hh:mm:ss");
            sleep(1);
            emit send2();
        }
    }
signals :
    void send(QString time_str);
    void send2();
};

















#endif // MYTHREAD_H
