#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class runningTimer : public QMainWindow
{
    Q_OBJECT

public:
    explicit runningTimer(QWidget *parent = nullptr);
    ~runningTimer();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
