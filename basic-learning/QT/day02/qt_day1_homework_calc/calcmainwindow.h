#ifndef CALCMAINWINDOW_H
#define CALCMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CalcMainWindow;
}

class CalcMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalcMainWindow(QWidget *parent = nullptr);
    ~CalcMainWindow();

private:
    Ui::CalcMainWindow *ui;
};

#endif // CALCMAINWINDOW_H
