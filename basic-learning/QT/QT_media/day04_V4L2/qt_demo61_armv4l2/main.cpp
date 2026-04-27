#include "videodisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    videodisplay w;
    w.show();

    return a.exec();
}
