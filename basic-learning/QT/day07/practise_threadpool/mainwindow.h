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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showdata(const QString &data);

private:
    Ui::MainWindow *ui;
    QThreadPool * manager;
};


static int count = 0;
static QMutex mutex;



class MytaskRunable:public QRunnable,public QObject
{
    Q_OBJECT
public:
    explicit MytaskRunable(QWidget *parent = nullptr){}
    ~MytaskRunable(){}
    void run() override
    {
        int i = 0;
        while (1) {
            //进入临界区访问临界资源
            mutex.lock();
            qDebug() << "---"<<QThread::currentThread()
                     <<QThread::currentThreadId();
            qDebug() << count++;
            emit sendData(QString::number(count));
            QThread::sleep(1);
            mutex.unlock();
        }
    }
signals:
    void sendData(const QString &data);
};



#endif // MAINWINDOW_H
