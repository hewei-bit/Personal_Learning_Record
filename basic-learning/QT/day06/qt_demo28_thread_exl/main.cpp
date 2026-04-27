#include "systemtime.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemTime w;
    w.show();

    return a.exec();
}
