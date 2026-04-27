#include "softbuttonwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoftButtonWin w;
    w.show();

    return a.exec();
}
