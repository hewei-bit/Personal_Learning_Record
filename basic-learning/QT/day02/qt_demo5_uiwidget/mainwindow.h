#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void test();

signals: //自定义信号
    void loginbtnenbled(); //信号函数不需要实现
    //在自己类中自定义槽函数
public slots:
    void setLoginBtnEnbled();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
