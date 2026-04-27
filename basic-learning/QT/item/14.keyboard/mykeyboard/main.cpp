#include "mykeyboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mykeyboard w;
    w.show();

    return a.exec();
}
