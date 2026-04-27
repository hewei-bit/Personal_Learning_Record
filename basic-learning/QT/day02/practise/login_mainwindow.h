#ifndef LOGIN_MAINWINDOW_H
#define LOGIN_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Login_MainWindow;
}

class Login_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login_MainWindow(QWidget *parent = nullptr);
    ~Login_MainWindow();


public slots:
    void LoginSuccess();



private:
    Ui::Login_MainWindow *ui;
};

#endif // LOGIN_MAINWINDOW_H
