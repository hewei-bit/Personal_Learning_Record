#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QtDebug>

//多线程编程通过跟线程同步结合使用
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
              qDebug() << "======MyThread" << this->objectName() << this->priority();
              for (int i=0;i<3;i++) {
                  QThread::sleep(1);
                  qDebug() << "======MyThread" << this->objectName() << i;
              }

        }

    }
};
#endif // MYTHREAD_H
