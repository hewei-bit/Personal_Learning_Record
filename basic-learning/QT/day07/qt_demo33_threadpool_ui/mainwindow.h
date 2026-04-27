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

//如果直接在QRunnable中使用信号和槽，声明Q_OBJECT就会出现以下错误
// error: 'staticMetaObject' is not a member of 'QRunnable'
 //    &QRunnable::staticMetaObject, 使用了Q_OBJECT，QT就会使用moc来编译
 //error: invalid use of non-static data member 'QObject::d_ptr' d_ptr应该是属于QObject
//解决办法：如果在QRunnable使用信号和槽，那么要使用多继承的方式，要继承QObject
//并且它的顺序要在QRunnable
class MyTaskRunnable:public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MyTaskRunnable(QWidget *parent = nullptr){}
    ~MyTaskRunnable(){}
    void run() override
    {
        int i=0;
        while (1) { //子线程要处理的事务
            QThread::sleep(1);
            emit sendData(QString::number(i++));
        }
    }
signals:
    void sendData(const QString &data);
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updateUI(const QString& data);
private:
    Ui::MainWindow *ui;
    QThreadPool * manager;
};

#endif // MAINWINDOW_H
