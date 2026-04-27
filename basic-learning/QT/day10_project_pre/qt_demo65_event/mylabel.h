#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEvent>

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MyLabel(QWidget *parent = nullptr);
    ~MyLabel();

    //对事件的处理，qt中的qlabel控件，没有鼠标点击事件
    //MyLabel  ---> QLabel --- ..... ---- QObject
    //重写父类虚函数
   // virtual bool event(QEvent* e);

    //Event hanlder
     virtual void mousePressEvent(QMouseEvent *event);
signals:
    void myonclicked();
};

#endif // MYLABEL_H
