#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class running_Timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit running_Timer(QWidget *parent = nullptr);
    ~running_Timer();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
