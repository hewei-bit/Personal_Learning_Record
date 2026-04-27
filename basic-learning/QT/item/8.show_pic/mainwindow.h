#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QFileInfo>
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
    void on_start_Btn_clicked();

    void on_stop_Btn_clicked();

    void show_picture(QString dirName);

private:
    Ui::MainWindow *ui;
    Mythread *th;


};

#endif // MAINWINDOW_H
