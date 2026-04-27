#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}


#ifdef __cplusplus
extern "C" {
#endif

////包含C的头文件和宏定义
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#ifdef __cplusplus
}
#endif


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
