#include "serialcrt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialCRT w;
    w.show();

    return a.exec();
}
