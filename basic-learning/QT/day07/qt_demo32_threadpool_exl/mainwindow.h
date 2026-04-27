#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRunnable>
#include <QtDebug>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
namespace Ui {
class MainWindow;
}
static int count = 0;
static QMutex mutex;

class MyTaskRunnable:public QRunnable
{
public:
    explicit MyTaskRunnable(QWidget *parent = nullptr){}
    ~MyTaskRunnable(){}
    void run() override
    {
        while (1) {
          mutex.lock();
         qDebug() <<"----"<< QThread::currentThreadId() << "count = " << count++;

         QThread::sleep(1);
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
};

#endif // MAINWINDOW_H
