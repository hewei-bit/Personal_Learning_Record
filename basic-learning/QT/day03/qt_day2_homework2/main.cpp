#include "teachersystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TeacherSystem w;
    w.show();

    return a.exec();
}
