#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec(); //执行一个循环事件，在这个事件中，就是监听是不是有事件发生了
}
