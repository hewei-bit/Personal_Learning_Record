#include "firstmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //创建一个QT应用程序
    FirstMainWindow w; //在栈上创建一个对象  ---- 窗口界面对象
                       // 只能是栈对象，不是堆对象
    w.show();  //显示窗口界面

   // FirstMainWindow* fmw = new FirstMainWindow; //在这里写是错误，会造成内存泄露
  //  fmw->show();
    //想要查看系统函数的功能说明，按F1,查看函数的作用，按ESC，函数说明消失
    return a.exec(); //qt应用程序可以进入一个死循环，避免程序退出
}
