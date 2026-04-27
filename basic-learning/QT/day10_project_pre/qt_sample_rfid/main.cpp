#include "serialrfid.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialRfid w;
    w.show();

    return a.exec();
}
