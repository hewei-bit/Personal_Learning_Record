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

    void setcolor(QPalette pal);

private slots:
    void on_redSlider_sliderMoved(int position);

    void on_greenSlider_2_sliderMoved(int position);

    void on_blueSlider_3_sliderMoved(int position);


    void on_setcolor_Btn_clicked();

    void on_paltte_1_Btn_clicked();

    void on_paltte_2_Btn_clicked();

    void on_paltte_3_Btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
