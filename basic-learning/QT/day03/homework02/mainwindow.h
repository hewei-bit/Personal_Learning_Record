#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

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
    void on_start_Btn_clicked();

    void on_reset_Btn_clicked();

    void on_count_Btn_clicked();

    void on_stop_Btn_clicked();

    void show_sec();
private:
    Ui::MainWindow *ui;
    QTimer* mTimer;
    static int num;
};

#endif // MAINWINDOW_H
