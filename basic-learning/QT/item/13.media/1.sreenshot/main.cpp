#include "sreen_shot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sreen_shot w;
    w.show();

    return a.exec();
}
