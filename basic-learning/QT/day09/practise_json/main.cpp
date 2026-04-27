#include "readjson.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    readJson w;
    w.show();

    return a.exec();
}
