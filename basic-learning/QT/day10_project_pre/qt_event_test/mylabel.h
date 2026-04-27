#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MyLabel(QWidget* parent = nullptr);
    ~MyLabel();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual bool event(QEvent *e);
signals:
    void myclicked();
};

#endif // MYLABEL_H
