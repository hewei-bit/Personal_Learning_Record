#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "systemtimethead.h"

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
    void getSystemTime(const QString& time);
    void updateSystemTime(const QTime& time);
private:
    Ui::MainWindow *ui;
    systemTimeThread* systemtimeth;
};

#endif // MAINWINDOW_H
