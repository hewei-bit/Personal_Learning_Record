#include "teacherwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TeacherWindow w;
    w.show();

    return a.exec();
}
