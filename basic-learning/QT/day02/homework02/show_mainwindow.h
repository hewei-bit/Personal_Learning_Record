#ifndef SHOW_MAINWINDOW_H
#define SHOW_MAINWINDOW_H

#include <QMainWindow>
#include "teacher.h"
namespace Ui {
class show_MainWindow;
}

class show_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_MainWindow(QWidget *parent = nullptr);
    ~show_MainWindow();

signals:
    void sendteacher(teacher tt);



public slots:
    void show_set_ui();
    void showteacher(teacher tt);
private:
    Ui::show_MainWindow *ui;
};

#endif // SHOW_MAINWINDOW_H
