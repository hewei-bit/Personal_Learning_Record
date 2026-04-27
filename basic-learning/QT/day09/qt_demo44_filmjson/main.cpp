#include "filminfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FilmInfo w;
    w.show();

    return a.exec();
}
