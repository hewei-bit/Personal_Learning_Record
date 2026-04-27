#ifndef SET_MAINWINDOW_H
#define SET_MAINWINDOW_H

#include <QMainWindow>
#include "teacher.h"
namespace Ui {
class set_MainWindow;
}

class set_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit set_MainWindow(QWidget *parent = nullptr);
    ~set_MainWindow();


public slots:
    void show_show_ui();

private:
    Ui::set_MainWindow *ui;
};

#endif // SET_MAINWINDOW_H
