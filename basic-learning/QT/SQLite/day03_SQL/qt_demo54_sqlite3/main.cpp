#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
//第一步，增加头文件
#include <sqlite3.h>

/*
参数一：void* ---sqlite3_exec 传传递的数据
参数二：int col --- 列的数目
参数三：char** value ---- 表的字段所对应的值
参数四：char** name ---- 表的字段名
返回值：0，否则，就不会继续调用回调函数
   如果sqlite3_exec()回调返回非零，
   sqlite3_exec()例程返回SQLITE_ABORT，而不会再次调用回调，也不会运行任何后续SQL语句。

*/
int callback(void* data ,int col,char** value,char** name)
{


    qDebug() << "col = "<< col;
    for(int i =0;i<col;i++)
    {
        qDebug() << *(value + i) ;
        qDebug() << *( name + i);
    }

     return  0; //返回值要设置为0，则表示执行sql语句成功
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    //w.show();
    int rc;
    sqlite3 *db = nullptr;
    rc = sqlite3_open("staff.db", &db); //参数一，传入参数  参数二，传出参数
      if( rc ){
         qDebug() << "Can't open database:" << sqlite3_errmsg(db);
         sqlite3_close(db);
         return(1);
       }

      rc = sqlite3_exec(db, "select * from user", callback, nullptr,nullptr);
      if( rc!=SQLITE_OK ){
          qDebug()<<"SQL error:";

        }

       sqlite3_close(db);
    return a.exec();
}
