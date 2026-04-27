#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
//如果在qt程序中，使用了linux头文件，那么编译程序只能去Linux下，进行交叉编译
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

private slots:
    void on_switchBtn_clicked();

private:
    Ui::MainWindow *ui;
    bool isLedState;
    int fd;
};

#endif // MAINWINDOW_H
