#include "staffwindow.h"
#include "ui_staffwindow.h"
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QListWidgetItem>
#include "itemform.h"
StaffWindow::StaffWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaffWindow)
{
    ui->setupUi(this);

    //创建和打开数据库
    //数据一个sqLite3数据库，QSQLITE ----> 对应sqlite3
    database = QSqlDatabase::addDatabase("QSQLITE");

   //给数据库取名字,该名字的后缀".db"
   database.setDatabaseName("company.db");

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
//   QString sqlTable = QString("CREATE TABLE staff"
//                              "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                              "name varchar(20) NOT NULL,"
//                              "age INTEGER NOT NULL,"
//                              "addr varchar(20) NOT NULL,"
//                              "salary INTEGER NOT NULL)");
//   qDebug() << sqlTable;

//   QSqlQuery sqlQuery; //创建该对象时，调用的是上面的构造函数，自动关联到数据库
//   sqlQuery.prepare(sqlTable);
//   if(!sqlQuery.exec())
//   {
//         qDebug() << "Error:Failed to create table"<< database.lastError();
//   }else {

//       qDebug() << "success create table";
//   }
}

StaffWindow::~StaffWindow()
{
    delete ui;
}

void StaffWindow::on_selectBtn_clicked()
{
    QSqlQuery sqlQuery;
    QString sqlSelect = QString("SELECT * FROM staff");
    if(!sqlQuery.exec(sqlSelect))
    {
          qDebug() << "Error:Failed to select record"<< database.lastError();
    }else {

        qDebug() << "success select record";
        //如果语句执行成功，要真正执行查询操作

        while (sqlQuery.next()) { //按行来进行遍历
            //int rowid = sqlQuery.value(0).toInt();
            int id = sqlQuery.value(0).toInt();
            QString name = sqlQuery.value(1).toString();
            int age = sqlQuery.value(2).toInt();
            QString addr = sqlQuery.value(3).toString();
            int salary = sqlQuery.value(4).toInt();
            // qDebug() << rowid;
            qDebug() << id;
            qDebug() << name;
            qDebug() << age;
            qDebug() << salary;
            QListWidgetItem * item = new QListWidgetItem();
            itemform* form = new itemform;
            form->setItem(id,name,age,addr,salary);
            item->setSizeHint(QSize(844,44));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,form);
        }
    }
}

void StaffWindow::on_delBtn_clicked()
{
    QSqlQuery sqlQuery;

    //删除记录
    QString sqlDelete = QString("DELETE FROM staff "
                                "WHERE id='%1'").arg(ui->idEdit->text());
    qDebug() << sqlDelete;

    if(!sqlQuery.exec(sqlDelete))
    {
          qDebug() << "Error:Failed to delete record"<< database.lastError();
    }else {
         qDebug() << "success delete record";
    }
}

void StaffWindow::on_addBtn_clicked()
{

}

void StaffWindow::on_updateBtn_clicked()
{
    ui->listWidget->clear();

    QSqlQuery sqlQuery;
    QString sqlSelect = QString("SELECT * FROM staff");
    if(!sqlQuery.exec(sqlSelect))
    {
          qDebug() << "Error:Failed to select record"<< database.lastError();
    }else {

        qDebug() << "success select record";
        //如果语句执行成功，要真正执行查询操作

        while (sqlQuery.next()) { //按行来进行遍历
            //int rowid = sqlQuery.value(0).toInt();
            int id = sqlQuery.value(0).toInt();
            QString name = sqlQuery.value(1).toString();
            int age = sqlQuery.value(2).toInt();
            QString addr = sqlQuery.value(3).toString();
            int salary = sqlQuery.value(4).toInt();
            // qDebug() << rowid;
            qDebug() << id;
            qDebug() << name;
            qDebug() << age;
            qDebug() << salary;
            QListWidgetItem * item = new QListWidgetItem();
            itemform* form = new itemform;
            form->setItem(id,name,age,addr,salary);
            item->setSizeHint(QSize(844,44));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,form);
        }
    }
}
