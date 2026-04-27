#include "qmplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qmplayer w;
    w.show();

    return a.exec();
}
