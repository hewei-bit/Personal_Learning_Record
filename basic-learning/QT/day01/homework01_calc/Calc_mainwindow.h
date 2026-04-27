#ifndef CALC_MAINWINDOW_H
#define CALC_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Calc_MainWindow;
}

class Calc_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calc_MainWindow(QWidget *parent = nullptr);
    ~Calc_MainWindow();

signals:
    void loginbtnenabled();

public slots:
    void setLoginBtnEnabled();

private:
    Ui::Calc_MainWindow *ui;
};

#endif // CALC_MAINWINDOW_H
