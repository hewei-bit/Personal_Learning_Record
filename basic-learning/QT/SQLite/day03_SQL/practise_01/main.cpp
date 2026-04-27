#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include <QtDebug>

//第一步添加头文件
#include "sqlite3.h"






int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();



    return a.exec();
}
