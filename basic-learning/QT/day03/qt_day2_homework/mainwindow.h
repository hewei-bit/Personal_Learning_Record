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

private slots:
    void on_starttestBtn_clicked();//对于UI的控件，可以右击 --> 转到槽,会自动生成槽函数，
                                    //并且建立信号与该槽函数的连接，开发者不需要再建立信号
                                    //和槽函数的连接

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
