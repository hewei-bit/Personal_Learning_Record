#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startThreadBtn_clicked();

    void on_stopThreadBtn_clicked();

private:
    Ui::MainWindow *ui;
    MyThread* th;
};

#endif // MAINWINDOW_H
