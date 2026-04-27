#include "studentwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentWin w;
    w.show();

    return a.exec();
}
