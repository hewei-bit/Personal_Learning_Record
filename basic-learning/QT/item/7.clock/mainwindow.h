#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTime"
#include "QTimer"
#include <mythread.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clock();
private slots:
    void startclock();
    void on_pushButton_clicked();
    void on_pushButton2_clicked();
    void showtime(QString time_str);
    void showtime2();
private:
    Ui::MainWindow *ui;
    QTimer *mtimer;
    Mythread* th;
};

#endif // MAINWINDOW_H
