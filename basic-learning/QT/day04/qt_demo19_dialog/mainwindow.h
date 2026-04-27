#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_conentBtn_clicked();

    void on_backgroudBtn_clicked();

    void on_fontsetBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
