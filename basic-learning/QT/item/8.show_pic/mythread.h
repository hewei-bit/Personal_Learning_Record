#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QMainWindow>
#include "QTime"
#include <QThread>
#include <QtDebug>
#include <QTime>

class Mythread:public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QWidget *parent = nullptr){}
    ~Mythread(){}

    void run() override
    {
        while(1)
        {
            sleep(1);
            static int i = 1;
            int num = i%18;
            QString dirName = QString(":/picture/p%1.png").arg(num);
            qDebug() << dirName;
            emit send(dirName);
            i++;
        }
    }
signals:
    void send(QString dirName);
};






#endif // MYTHREAD_H
