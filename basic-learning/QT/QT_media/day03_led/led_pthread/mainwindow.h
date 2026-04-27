#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QRunnable>
#include <QtDebug>
#include <QThread>
#include <QThreadPool>
#include <QMutex>


#ifndef __cplusplus
extern "C"{
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#ifndef __cplusplus
}
#endif


static QMutex mutex;

class led_run:public QThread
{
    Q_OBJECT
public:
    explicit led_run(QWidget *parent = nullptr){}
    ~led_run(){}

    void run() override
    {
        mutex.lock();
        while(1)
        {
        QThread::sleep(1);
        qDebug() << "led_run";
        emit send();
        mutex.unlock();
    }}

signals:
    void send();
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void led_running();
private slots:
    void on_d7Btn_clicked();

    void on_D8Btn_clicked();

    void on_D9Btn_clicked();

    void on_D10Btn_clicked();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    int fd ;
    int isRunning;
};

#endif // MAINWINDOW_H
