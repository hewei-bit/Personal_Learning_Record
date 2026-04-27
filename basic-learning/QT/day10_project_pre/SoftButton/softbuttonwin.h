#ifndef SOFTBUTTONWIN_H
#define SOFTBUTTONWIN_H

#include <QMainWindow>

namespace Ui {
class SoftButtonWin;
}

class SoftButtonWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit SoftButtonWin(QWidget *parent = 0);
    ~SoftButtonWin();
    bool eventFilter(QObject *watched, QEvent *event);
    void callKeyBoard();


private slots:
    void on_loginBtn_clicked();

    void on_userEdit_2_editingFinished();

    void on_passwordEdit_editingFinished();

private:
    Ui::SoftButtonWin *ui;
};

#endif // SOFTBUTTONWIN_H
