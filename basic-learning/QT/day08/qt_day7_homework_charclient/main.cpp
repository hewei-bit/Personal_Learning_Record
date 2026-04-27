#include "charclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CharClient w;
    w.show();

    return a.exec();
}
