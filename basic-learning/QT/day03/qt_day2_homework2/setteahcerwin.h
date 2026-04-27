#ifndef SETTEAHCERWIN_H
#define SETTEAHCERWIN_H

#include <QMainWindow>
#include "teacher.h"

namespace Ui {
class SetTeahcerWin;
}

class SetTeahcerWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetTeahcerWin(QWidget *parent = nullptr);
    ~SetTeahcerWin();

signals:
    void sendTeacherModifed(Teacher t);
private slots:
    void on_backBtn_clicked();

private:
    Ui::SetTeahcerWin *ui;
};

#endif // SETTEAHCERWIN_H
