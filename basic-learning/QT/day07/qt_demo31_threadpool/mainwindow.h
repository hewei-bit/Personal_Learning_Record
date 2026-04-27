#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRunnable>
#include <QtDebug>
#include <QThread>
#include <QThreadPool>
namespace Ui {
class MainWindow;
}

//QRunnable是一个抽象类，virtual void run() = 0
class MyTaskRunnable:public QRunnable
{
public:
    explicit MyTaskRunnable(QWidget *parent = nullptr){}
    ~MyTaskRunnable(){}
    void run() override
    {
        while (1) {
         qDebug() <<"----"<<QThread::currentThread()
                 << QThread::currentThreadId();
         QThread::sleep(1);
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
};

#endif // MAINWINDOW_H
