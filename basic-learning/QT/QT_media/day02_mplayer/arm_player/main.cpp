#include "arm_player.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ARM_player w;
    w.show();

    return a.exec();
}
