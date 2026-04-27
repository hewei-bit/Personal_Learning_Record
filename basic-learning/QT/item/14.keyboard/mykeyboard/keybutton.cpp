#include "keybutton.h"



keybutton::keybutton(QWidget *parent)
{
    connect(this,&keybutton::clicked,this,&keybutton::button_click);
}

keybutton::keybutton(const QString &text, QWidget *parent)
{
    connect(this,&keybutton::clicked,this,&keybutton::button_click);
}

keybutton::keybutton(const QIcon &icon, const QString &text, QWidget *parent)
{
    connect(this,&keybutton::clicked,this,&keybutton::button_click);
}

void keybutton::button_click()
{
    //获取按键字符串
    QString str = this->text();
    qDebug()<<str;

    //模拟键盘q键按下---自定义一个q键事件
    QKeyEvent *key = nullptr;

    if(QString("0123456789qwertyuiopasdfghjklzxcvbnm,.").contains(str) && !str.isEmpty())
    {
        char ch = str.at(0).toLatin1();
        key = new QKeyEvent(QKeyEvent::KeyPress,ch,Qt::NoModifier,str);
    }
    //定义一个事件，Key_Backspace撤消按钮
    else if(str == "Del")
    {
        //定义一个事件，Key_Backspace撤消按钮
       key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Backspace,Qt::NoModifier);

    }else if(str == "Enter")
    {
       key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Return,Qt::NoModifier);

    }
    else if(str.isEmpty())
    {
       key = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Space,Qt::NoModifier," ");
    }


    //通过postEvent将事件key发送出去
    QApplication::postEvent(QApplication::focusWidget(),key);


}
