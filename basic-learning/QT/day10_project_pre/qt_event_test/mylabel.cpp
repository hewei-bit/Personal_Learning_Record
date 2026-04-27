#include "mylabel.h"
#include <QMouseEvent>
#include <QtDebug>


MyLabel::MyLabel(QWidget* parent): QLabel(parent)
{

      qDebug() << " ======";
}

MyLabel::~MyLabel()
{

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{

//    if(event->button() == Qt::LeftButton)
//    {
//        this->setStyleSheet("background-color: rgb(255, 0, 0);");
//    }else {
//        qDebug() << " do not";
//    }
    emit myclicked();
}

bool MyLabel::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
     {
         //将QEvent对象转换为真正的QKeyEvent对象QMouseEvent
         QMouseEvent *keyEvent = static_cast<QMouseEvent *>(e);
         if (keyEvent->button() == Qt::LeftButton)
         {
             qDebug() << "You press left.";
             return true;
         }
     }
     //直接返回false
  //  return  false;
     return QLabel::event(e);
}
