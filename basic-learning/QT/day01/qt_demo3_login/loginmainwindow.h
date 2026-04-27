#ifndef LOGINMAINWINDOW_H
#define LOGINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginMainWindow;
}

class LoginMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginMainWindow(QWidget *parent = nullptr);
    ~LoginMainWindow();

private:
    Ui::LoginMainWindow *ui;
};

#endif // LOGINMAINWINDOW_H
