#include "login_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_MainWindow w;
    w.show();

    return a.exec();
}
