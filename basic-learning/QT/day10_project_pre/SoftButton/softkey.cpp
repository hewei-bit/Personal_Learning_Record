#include "softkey.h"
#include <QKeyEvent>
#include <QApplication>
SoftKey::SoftKey(QWidget *parent):QToolButton(parent)
{
  connect(this,SIGNAL(clicked(bool)),this,SLOT(button_clicked(bool)));
}

void SoftKey::button_clicked(bool)
{

    if(this->text() == "<-")
       {
        //定义一个事件，Key_Backspace撤消按钮
           QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier, this->text());
            //通过postEvent将事件key发送出去
           QApplication::postEvent(QApplication::focusWidget(),key);
       }else
       {
           QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,'w',Qt::NoModifier, this->text());
           //通过postEvent将事件key的文本内容发送出去，QApplication::focusWidget()当前窗口中，有光标的
           //控件上
           QApplication::postEvent(QApplication::focusWidget(),key);
       }
}
