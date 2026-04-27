#include "teacher_system_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    teacher_system_MainWindow w;
    w.show();

    return a.exec();
}
