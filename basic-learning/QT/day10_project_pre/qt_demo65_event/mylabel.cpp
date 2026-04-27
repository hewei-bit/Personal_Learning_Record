#include "mylabel.h"

#include <QMouseEvent>
#include <QtDebug>

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{

}

MyLabel::~MyLabel()
{

}
#if 0
bool MyLabel::event(QEvent *e) //QEvent是所有事件的基类
{
       //
    if(e->type() == QEvent::MouseButtonPress)
    {
        //将QEvent对象转换成真正的QMouseEvent对象
          QMouseEvent* mouseEvent =  static_cast< QMouseEvent*>(e);

          //通过处理事件，比如，鼠标左边点击了
          if(mouseEvent->button() == Qt::LeftButton)
          {
                qDebug() << "------you click left button";
                return true; //返回true，表示对该事件进行了处理，该事件就不会往下分发了
          }
    }

    //其他的事件，按照原来的流程来进行事件的分发
    return  QLabel::event(e);
}
#endif
void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
          qDebug() << "you click left button";
          this->setStyleSheet(QString("color:red;"));
          emit myonclicked();
         //返回true，表示对该事件进行了处理，
    }
}
