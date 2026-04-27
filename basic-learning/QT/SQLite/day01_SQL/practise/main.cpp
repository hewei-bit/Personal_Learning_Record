#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow w;
    w.show();
    //使用dirver接口来查询驱动支持类型
//    QStringList dirvers = QSqlDatabase::drivers();
//    qDebug() << dirvers;
//    QString dirver;
//    foreach(dirver,dirvers)
//    {
//        qDebug() << dirver;
//    }

    return a.exec();
}
