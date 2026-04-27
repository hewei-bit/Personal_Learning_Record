#include "staffsystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    staffsystem w;
    w.show();

    return a.exec();
}
