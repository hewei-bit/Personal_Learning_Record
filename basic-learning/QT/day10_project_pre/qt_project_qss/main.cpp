#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //定制皮肤在程序运行之前设置
        QFile file(":/qss/mystyle.qss");
        file.open(QIODevice::ReadOnly);
       QByteArray array =  file.readAll();
      // #define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
       qApp->setStyleSheet(array);
    MainWindow w;
    w.show();

    return a.exec();
}
