#include "teacher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    teacher w;
    w.show();

    return a.exec();
}
