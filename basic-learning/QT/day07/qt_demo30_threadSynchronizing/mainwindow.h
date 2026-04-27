#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtDebug>
#include <QMutex>

namespace Ui {
class MainWindow;
}

static int number = 0;
static QMutex mutex;
//创建线程1
class WorkThread1:public QThread
{
public:
    explicit WorkThread1(QWidget *parent = nullptr)
    {}
    ~WorkThread1(){}
    void run()override
    {
        while (1) {
            //临界区：临界资源的上下文  临界资源：共享变量，
            mutex.lock();
            QThread::sleep(2);
            qDebug() << "WorkThread1" << number++;
            mutex.unlock();
        }
    }

};

//创建线程2
class WorkThread2:public QThread
{
public:
    explicit WorkThread2(QWidget *parent = nullptr)
    {}
    ~WorkThread2(){}
    void run()override
    {
        while (1) {
            mutex.lock();
            QThread::sleep(1);
            qDebug() << "WorkThread2" << number++;
            mutex.unlock();
        }
    }

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    WorkThread2* w2;
    WorkThread1* w1;
};

#endif // MAINWINDOW_H
