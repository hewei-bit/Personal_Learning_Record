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

   //以上两个步骤，相当于创建一个数据库文件，要使用专门工具来访问和打开，不能像访问
   //标准IO，和json文件 ，它要使用专业 的SQL语言来进行操作数据库
   //打开数据库
  // bool ok = database.open();
   if(!database.open())
   {
      //数据库打开 失败
       qDebug() << "Error:Failed to connect DataBase"<<database.lastError();
   }

   //创建一个表  create table --- sql语句大小写不敏感
   QString sqlTable = QString("CREATE TABLE cargo"
                              "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "shopname varchar(20) NOT NULL,"
                              "price INTEGER NOT NULL,"
                              "shopstore INTEGER NOT NULL)");
  qDebug() << sqlTable;

   QSqlQuery sqlQuery; //创建该对象时，调用的是上面的构造函数，自动关联到数据库
   sqlQuery.prepare(sqlTable);
   if(!sqlQuery.exec())
   {
         qDebug() << "Error:Failed to create table"<< database.lastError();
   }else {

       qDebug() << "success create table";
   }

   QString sqlInsert = QString("INSERT INTO cargo(shopname,price,shopstore) values('apple',6,100)");

//   if(!sqlQuery.exec(sqlInsert))
//   {
//         qDebug() << "Error:Failed to insert record"<< database.lastError();
//   }else {

//       qDebug() << "success insert record";
//   }

   //查询记录
   QString sqlSelect = QString("SELECT * FROM cargo"); //* 代表所有字段的信息
   if(!sqlQuery.exec(sqlSelect))
   {
         qDebug() << "Error:Failed to select record"<< database.lastError();
   }else {

       qDebug() << "success select record";
       //如果语句执行成功，要真正执行查询操作

       while (sqlQuery.next()) { //按行来进行遍历
           int id = sqlQuery.value(0).toInt(); //按列的下标来进行读取，还可以通过字段名来读取
           QString shopname = sqlQuery.value(1).toString();
           int price = sqlQuery.value(2).toInt();
           int shopstroe = sqlQuery.value(3).toInt();

           qDebug() << id <<"  "<< shopname << "  "<< price << "   " << shopstroe;
       }
   }
#if 1
   //修改
   QString sqlUpdata = QString("UPDATE cargo SET "
                               " price= 10,shopstore=200 "
                               "WHERE shopname='apple'");

   if(!sqlQuery.exec(sqlUpdata))
   {
         qDebug() << "Error:Failed to update record"<< database.lastError();
   }else {
         qDebug() << "success update record";
   }


   QString sqlSelect1 = QString("SELECT * FROM cargo");
   if(!sqlQuery.exec(sqlSelect1))
   {
         qDebug() << "Error:Failed to select record"<< database.lastError();
   }else {

       qDebug() << "success select record";
       //如果语句执行成功，要真正执行查询操作

       while (sqlQuery.next()) { //按行来进行遍历
           int id = sqlQuery.value(0).toInt();
           QString shopname = sqlQuery.value(1).toString();
           int price = sqlQuery.value(2).toInt();
           int shopstroe = sqlQuery.value(3).toInt();

           qDebug() << id <<"  "<< shopname << "  "<< price << "   " << shopstroe;

       }
   }
#endif

   //删除记录
   QString sqlDelete = QString("DELETE FROM cargo "
                               "WHERE shopname='apple'");
   if(!sqlQuery.exec(sqlDelete))
   {
         qDebug() << "Error:Failed to delete record"<< database.lastError();
   }else {
        qDebug() << "success delete record";
   }

   //查询删除后记录
   QString sqlSelect2 = QString("SELECT * FROM cargo"); //* 代表所有字段的信息
   if(!sqlQuery.exec(sqlSelect))
   {
         qDebug() << "Error:Failed to select record"<< database.lastError();
   }else {

       qDebug() << "success select record";
       //如果语句执行成功，要真正执行查询操作

       while (sqlQuery.next()) { //按行来进行遍历
           int id = sqlQuery.value(0).toInt(); //按列的下标来进行读取，还可以通过字段名来读取
           QString shopname = sqlQuery.value(1).toString();
           int price = sqlQuery.value(2).toInt();
           int shopstroe = sqlQuery.value(3).toInt();

           qDebug() << id <<"  "<< shopname << "  "<< price << "   " << shopstroe;
       }
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}
