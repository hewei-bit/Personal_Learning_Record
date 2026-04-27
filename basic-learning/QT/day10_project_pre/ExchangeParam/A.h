#ifndef A_H
#define A_H

#include <QWidget>
#include <QString>
#include <QCloseEvent>
#include "B.h"
#include "C.h"

namespace Ui {
class A;
}

class A : public QWidget
{
    Q_OBJECT

public:
    explicit A(QWidget *parent = 0);
    B *b;
    C *c;

    ~A();

protected:
    void closeEvent(QCloseEvent *event);


private:
    Ui::A *ui;

private slots:
    void fromB(QString);
    void fromC(QString);

    void pushB();
    void pushC();
};

#endif // A_H
