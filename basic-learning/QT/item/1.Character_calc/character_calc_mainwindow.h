#ifndef CHARACTER_CALC_MAINWINDOW_H
#define CHARACTER_CALC_MAINWINDOW_H


#include <QMainWindow>

namespace Ui {
class character_calc_MainWindow;
}

class character_calc_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit character_calc_MainWindow(QWidget *parent = nullptr);
    ~character_calc_MainWindow();



public slots:
    void showresult();


private:
    Ui::character_calc_MainWindow *ui;
};

#endif // CHARACTER_CALC_MAINWINDOW_H
