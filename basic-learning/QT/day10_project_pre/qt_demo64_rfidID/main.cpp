#include "mainwindow.h"
#include <QApplication>
#include "readrfidid.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LED w;
    w.show();

    while(1)
    {

        readCardId();
        sleep(1);
    }
    return a.exec();
}
