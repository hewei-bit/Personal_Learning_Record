#include "qsqliteoperator.h"
#include "ui_qsqliteoperator.h"
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
QsqliteOperator::QsqliteOperator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QsqliteOperator)
{
    ui->setupUi(this);
    //数据一个sqLite3数据库，QSQLITE ----> 对应sqlite3
   QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");

   //给数据库取名字,该名字的后缀".db"
   database.setDatabaseName("mydatabase.db");

   //以上两个步骤，相当于创建一个数据库文件，要使用专门工具来访问和打开，不能像访问
   //标准IO，和json文件 ，它要使用专业 的SQL语言来进行操作数据库
   //打开数据库
  // bool ok = database.open();
   if(!database.open())
   {
      //数据库打开 失败
       qDebug() << "Error:Failed to connect DataBase"<<database.lastError();
   }

   //数据库的操作主要包括：创建表，增加，删除，修改，查询表中的数据 --- 都是通过sql语句
   //sql语句是由--QSqlQuery来执行
   //创建一个表  create table --- sql语句大小写不敏感
   QString sqlTable = QString("CREATE TABLE student"
                              "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "name varchar(20) NOT NULL,"
                              "age INTEGER NOT NULL)");
   qDebug() << sqlTable;

   //执行sql语句


  // QSqlQuery(const QString &query = QString(), QSqlDatabase db = QSqlDatabase())

   QSqlQuery sqlQuery; //创建该对象时，调用的是上面的构造函数，自动关联到数据库
//   sqlQuery.prepare(sqlTable);
//   if(!sqlQuery.exec())
//   {
//         qDebug() << "Error:Failed to create table"<< database.lastError();
//   }else {

//       qDebug() << "success create table";
//   }

   //创建表的语句，数据库创建和打开 只需要执行一次

   //QSqlQuery 如何跟数据库进行关联 QSqlDatabase

   //插入记录到数据库表中

  QString sqlInsert = QString("insert into student(name,age) values('张三',20)");

  if(!sqlQuery.exec(sqlInsert))
  {
        qDebug() << "Error:Failed to insert record"<< database.lastError();
  }else {

      qDebug() << "success insert record";
  }

  //查询记录
  QString sqlSelect = QString("SELECT * FROM student");
  if(!sqlQuery.exec(sqlSelect))
  {
        qDebug() << "Error:Failed to select record"<< database.lastError();
  }else {

      qDebug() << "success select record";
      //如果语句执行成功，要真正执行查询操作

      while (sqlQuery.next()) { //按行来进行遍历
          int id = sqlQuery.value(0).toInt();
          QString name = sqlQuery.value(1).toString();
          int age = sqlQuery.value(2).toInt();

          qDebug() << id;
          qDebug() << name;
          qDebug() << age;
      }
  }
}

QsqliteOperator::~QsqliteOperator()
{
    delete ui;
}
