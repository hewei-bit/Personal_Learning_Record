#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //使用dirver接口来查询驱动支持类型
   QStringList dirvers =  QSqlDatabase::drivers();
    qDebug() << dirvers;
   //QStringList ---- 专门用于存储字符串的列表容器
   //在QT中遍历容器中的条目数据的方法有三种：JAVA类型迭代器，STL标准库迭代，foreach关键字
   //Qt also offers a foreach keyword that make
   //        it very easy to iterate over all the items stored in a container.
   /*
 QLinkedList<QString> list; //容器

  QString str; //容器中数据的类型
  foreach (str, list) ---参数一 容器中的数据类型变量，参数二：容器对象名字
      qDebug() << str;

   */
   foreach(QString dirver,dirvers)
   {
       qDebug() << dirver;
   }
  //  MainWindow w;
   // w.show();

    return a.exec();
}
