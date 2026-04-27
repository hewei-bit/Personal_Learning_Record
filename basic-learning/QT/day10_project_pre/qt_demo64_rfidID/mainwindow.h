#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class LED : public QMainWindow
{
    Q_OBJECT

public:
    explicit LED(QWidget *parent = nullptr);
    ~LED();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
