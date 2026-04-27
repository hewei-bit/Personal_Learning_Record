#include "screencut.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScreenCut w;
    w.show();

    return a.exec();
}
