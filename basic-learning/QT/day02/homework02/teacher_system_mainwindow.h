#ifndef TEACHER_SYSTEM_MAINWINDOW_H
#define TEACHER_SYSTEM_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class teacher_system_MainWindow;
}

class teacher_system_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacher_system_MainWindow(QWidget *parent = nullptr);
    ~teacher_system_MainWindow();

public slots:
    void show_show_ui();

private:
    Ui::teacher_system_MainWindow *ui;
};

#endif // TEACHER_SYSTEM_MAINWINDOW_H
