#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //数据一个sqLite3数据库，QSQLITE ----> 对应sqlite3
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");

    //给数据库取名字,该名字的后缀".db"
    database.setDatabaseName("shop.db");

    //打开数据库
    //bool ok = database.open();
    if(!database.open())
    {
        qDebug() << "Error:Failed to connect DataBase"<<database.lastError();
    }

    QString sqlTable = QString("create table cargo"
                               "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "name varcahr(20) not null,"
                               "price interger not null,"
                               "num integer not null)");
    qDebug() << sqlTable;

    //    QSqlQuery sqlQuery(sqlTable,database);
    // QSqlQuery(const QString &query = QString(), QSqlDatabase db = QSqlDatabase())
    QSqlQuery sqlQuery; //创建该对象时，调用的是上面的构造函数，自动关联到数据库

    //创建表的语句，数据库创建和打开 只需要执行一次
    //QSqlQuery 如何跟数据库进行关联 QSqlDatabase

    sqlQuery.prepare(sqlTable);
    if(!sqlQuery.exec())
    {
        qDebug() << "prepare error";
    }
    else {
        qDebug() << "prepare success";
    }

#if 0
    //插入记录到数据库表中
    QString sqlInsert = QString("insert into cargo(name,price,num) values('苹果',24,100)");
    if(!sqlQuery.exec(sqlInsert))
    {
          qDebug() << "Error:Failed to insert record"<< database.lastError();
    }else {

        qDebug() << "success insert record";
    }

    sqlInsert = QString("insert into cargo(name,price,num) values('pear',28,100)");
    if(!sqlQuery.exec(sqlInsert))
    {
          qDebug() << "Error:Failed to insert record"<< database.lastError();
    }else {

        qDebug() << "success insert record";
    }

    sqlInsert = QString("insert into cargo(name,price,num) values('watermelon',27,100)");
    if(!sqlQuery.exec(sqlInsert))
    {
          qDebug() << "Error:Failed to insert record"<< database.lastError();
    }else {

        qDebug() << "success insert record";
    }

    sqlInsert = QString("insert into cargo(name,price,num) values('pine',26,100)");
    if(!sqlQuery.exec(sqlInsert))
    {
          qDebug() << "Error:Failed to insert record"<< database.lastError();
    }else {

        qDebug() << "success insert record";
    }

    sqlInsert = QString("insert into cargo(name,price,num) values('pineapple',25,100)");

    if(!sqlQuery.exec(sqlInsert))
    {
          qDebug() << "Error:Failed to insert record"<< database.lastError();
    }else {

        qDebug() << "success insert record";
    }
#endif


    //修改记录
    QString sqlupdate = QString("update cargo "
                                "set name = 'pearrr' "
                                "where price = 28");
//    if(!sqlQuery.exec(sqlupdate))
//    {
//          qDebug() << "Error:Failed to sqlupdate record"<< database.lastError();
//    }else {

//        qDebug() << "success sqlupdate record";
//    }


#if 0
    //删除记录
    QString sqldelete = QString("delete from cargo "
                                "where name='pineapple'");
    if(!sqlQuery.exec(sqldelete))
    {
          qDebug() << "Error:Failed to delete record"<< database.lastError();
    }else {
        qDebug() << "success delete record";
    }
#endif
    //查询记录
    QString sqlSelect = QString("select * from cargo");
    if(!sqlQuery.exec(sqlSelect))
    {
          qDebug() << "Error:Failed to insert record"<< database.lastError();
    }else {

        qDebug() << "select insert record";
         //如果语句执行成功，要真正执行查询操作
        while(sqlQuery.next())//按行来进行遍历
        {
            int id = sqlQuery.value(0).toInt();
            QString name = sqlQuery.value(1).toString();
            int price = sqlQuery.value(2).toInt();
            int num = sqlQuery.value(3).toInt();

            qDebug() << id << name << price<< num;

        }
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}
