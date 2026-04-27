#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "v4l2.h"
#include <QTimer>
#include <QPixmap>

#include <QListWidgetItem>
namespace Ui {
class MainWindow;
}

class LED : public QMainWindow
{
    Q_OBJECT

public:
    explicit LED(QWidget *parent = nullptr);
    ~LED();

private slots:
    void on_startBtn_2_clicked();

    void on_startBtn_clicked();

    void flushButff();

    void on_startBtn_3_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:

    Ui::MainWindow *ui;

    pass_data pd; //定义一个相关的摄像头对象
    unsigned char *bufrgb; //获取摄像头数据指针
    QTimer timer;

};

#endif // MAINWINDOW_H
