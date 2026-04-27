#include "A.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    A w;
    w.show();

    return a.exec();
}
