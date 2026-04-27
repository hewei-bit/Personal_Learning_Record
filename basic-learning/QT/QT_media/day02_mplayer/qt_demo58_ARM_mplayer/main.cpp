#include "mainwindow.h"
#include <QApplication>
#include "qplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
   // w.show();

    QPlayer p;
    p.show();
    return a.exec();
}
