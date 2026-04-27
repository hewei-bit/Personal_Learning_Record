#ifndef C_H
#define C_H

#include <QWidget>
#include <QString>

namespace Ui {
class C;
}

class C : public QWidget
{
    Q_OBJECT

public:
    explicit C(QWidget *parent = 0);
    ~C();
    void fromA(QString);

private:
    Ui::C *ui;

private slots:
    void fromB(QString);

    void pushA();
    void pushB();

signals:
    void toA(QString);
    void toB(QString);
};

#endif // C_H
