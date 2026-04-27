#ifndef B_H
#define B_H

#include <QWidget>
#include <QString>

namespace Ui {
class B;
}

class B : public QWidget
{
    Q_OBJECT

public:
    explicit B(QWidget *parent = 0);
    ~B();

    void fromA(QString);
private:
    Ui::B *ui;

private slots:
    void fromC(QString);

    void pushA();
    void pushC();

signals:
    void toA(QString);
    void toC(QString);

};

#endif // B_H
