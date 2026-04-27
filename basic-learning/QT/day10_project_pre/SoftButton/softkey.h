#ifndef SOFTKEY_H
#define SOFTKEY_H

#include <QToolButton>

class SoftKey : public QToolButton
{
    Q_OBJECT
public:
     explicit SoftKey(QWidget *parent = Q_NULLPTR);

private slots:
    void button_clicked(bool);
};

#endif // SOFTKEY_H
