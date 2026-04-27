#ifndef KEYBUTTON_H
#define KEYBUTTON_H


#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QPushButton>
#include <QString>


class keybutton:public QPushButton
{


public:
    explicit keybutton(QWidget *parent = nullptr);
    explicit keybutton(const QString &text,QWidget *parent = nullptr);
    keybutton(const QIcon &icon, const QString &text,QWidget *parent = nullptr);


private slots:
    void button_click();
};

#endif // KEYBUTTON_H
