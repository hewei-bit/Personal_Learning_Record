#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QtDebug>

class MyThread : public  QThread
{
    Q_OBJECT
public:
    explicit MyThread(QWidget *parent = nullptr)
    {

    }
    ~MyThread(){}

    //重写虚函数
    void run() override {
     //子线程处理事务的地方，不能维护长期运行
        while (1) {
              qDebug() << "======MyThread";
                QThread::sleep(1);

        }

    }
};
#endif // MYTHREAD_H
