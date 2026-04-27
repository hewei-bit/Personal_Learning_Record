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
    void initUi();
private slots:
    void on_startBtn_clicked(bool checked);

    void on_pauseBtn_clicked(bool checked);

    void on_prevBtn_clicked();

    void on_nextBtn_clicked();

    void on_stopBtn_clicked();

private:
    Ui::MainWindow *ui;

    bool isState;
};

#endif // MAINWINDOW_H
