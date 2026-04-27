#ifndef MUSICPLAYER_MAINWINDOW_H
#define MUSICPLAYER_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Musicplayer_MainWindow;
}

class Musicplayer_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Musicplayer_MainWindow(QWidget *parent = nullptr);
    ~Musicplayer_MainWindow();

    void init();
    bool isStatus = false;

private slots:
    void on_begin_pushButton_clicked();

    void on_stop_conti_pushButton_clicked();

    void on_close_pushButton_5_clicked();

private:
    Ui::Musicplayer_MainWindow *ui;
};

#endif // MUSICPLAYER_MAINWINDOW_H
