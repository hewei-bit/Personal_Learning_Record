#include "character_calc_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    character_calc_MainWindow w;
    w.show();

    return a.exec();
}
