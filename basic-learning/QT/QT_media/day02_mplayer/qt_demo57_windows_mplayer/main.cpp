#include "qplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPlayer w;
    w.show();

    return a.exec();
}
