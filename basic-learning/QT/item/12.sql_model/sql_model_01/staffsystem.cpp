#include "staffsystem.h"
#include "ui_staffsystem.h"
#include "itemform.h"
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

staffsystem::staffsystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staffsystem)
{
    ui->setupUi(this);

    open();

    //创建一个表  create table --- sql语句大小写不敏感
//    QString sqlTable = QString("CREATE TABLE staff("
//                               "name VARCHAR(100) NOT NULL, "
//                               "age VARCHAR(100) NOT NULL, "
//                               "address VARCHAR(100) NOT NULL,"
//                               "salary INTEGER NOT NULL)");
//    qDebug() << sqlTable;

//     QSqlQuery sqlQuery; //创建该对象时，调用的是上面的构造函数，自动关联到数据库
//     sqlQuery.prepare(sqlTable);
//     if(!sqlQuery.exec())
//     {
//           qDebug() << "Error:Failed to create table"<< database.lastError();
//     }else {

//         qDebug() << "success create table";
//     }


}

staffsystem::~staffsystem()
{
    delete ui;
}

bool staffsystem::open()
{
    //数据一个sqLite3数据库，QSQLITE ----> 对应sqlite3
    database = QSqlDatabase::addDatabase("QSQLITE");

    //给数据库取名字,该名字的后缀".db"
    database.setDatabaseName("../sql_model_01/staff.db");

    if(!database.open())
    {
       //数据库打开 失败
        qDebug() << "Error:Failed to connect DataBase"<<database.lastError();
        return false;
    }
    return true;
}

void staffsystem::clearsheet()
{
    for (;ui->tableWidget->rowCount()!=0;) {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
    }
}

void staffsystem::readdb()
{
    clearsheet();
    sqlQuery = QSqlQuery(database);
    sqlSelect = QString("SELECT * FROM staff"); //* 代表所有字段的信息
    if(!sqlQuery.exec(sqlSelect))
    {
          qDebug() << "Error:Failed to select record"<< database.lastError();
    }else
    {

        qDebug() << "success select record";
        //如果语句执行成功，要真正执行查'询操作

        for (int i = 0;sqlQuery.next();i++)
        { //按行来进行遍历

            int id = sqlQuery.value(0).toInt();
            QString name = sqlQuery.value(1).toString();
            int age = sqlQuery.value(2).toInt();
            QString address = sqlQuery.value(3).toString();
            int salary = sqlQuery.value(4).toInt();

            qDebug() << "id" << id<< name <<"  "<< age << "  "<< address << "   " << salary;

            QTableWidgetItem *itemid = new QTableWidgetItem();
            itemid->setText(QString::number(id));
            QTableWidgetItem *itemname= new QTableWidgetItem();
            itemname->setText(name);
            QTableWidgetItem *itemage = new QTableWidgetItem();
            itemage->setText(QString::number(age));
            QTableWidgetItem *itemaddress = new QTableWidgetItem();
            itemaddress->setText(address);
            QTableWidgetItem *itemsalary = new QTableWidgetItem();
            itemsalary->setText(QString::number(salary));

            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,itemid);
            ui->tableWidget->setItem(i,1,itemname);
            ui->tableWidget->setItem(i,2,itemage);
            ui->tableWidget->setItem(i,3,itemaddress);
            ui->tableWidget->setItem(i,4,itemsalary);

        }
    }
}

void staffsystem::on_add_Btn_clicked()
{
    sqlQuery = QSqlQuery(database);

    QString id = ui->ID_lineEdit->text();
    QString name = ui->name_lineEdit->text();
    QString age = ui->age_lineEdit_2->text();
    QString address = ui->address_lineEdit->text();
    QString salary = ui->salary_lineEdit->text();

    sqlInsert = QString("insert into "
                        "staff(id,name,age,address,salary) "
                        "values(%1,'%2',%3,'%4',%5)").arg(id,name,age,address,salary);

    sqlQuery.exec(sqlInsert);

    readdb();

}

void staffsystem::on_renew_Btn_clicked()
{
    sqlQuery = QSqlQuery(database);
    int row = ui->tableWidget->currentRow();
    QString id = ui->tableWidget->item(row,0)->text();
    QString name = ui->tableWidget->item(row,1)->text();
    QString age = ui->tableWidget->item(row,2)->text();
    QString address = ui->tableWidget->item(row,3)->text();
    QString salary = ui->tableWidget->item(row,4)->text();
    qDebug() << "id" << id<< name <<"  "<< age << "  "<< address << "   " << salary;
    sqlupdate = QString("update staff "
                        "set id=%1,name = '%2',age=%3,address='%4',salary=%5 "
                        "where id = %6").arg(id,name,age,address,salary,id);
    qDebug() << salary;
    sqlQuery.exec(sqlupdate);

    readdb();

}

void staffsystem::on_delete_Btn_clicked()
{
    sqlQuery = QSqlQuery(database);
    int row = ui->tableWidget->currentRow();

    sqldelete = QString("DELETE FROM staff "
                        "WHERE id='%1'").arg(ui->tableWidget->item(row,0)->text());
    qDebug()<< "delete";
    if(!sqlQuery.exec(sqldelete))
    {
          qDebug() << "Error:Failed to delete record"<< database.lastError();
    }else {
         qDebug() << "success delete record";
    }

    readdb();

}

void staffsystem::on_check_Btn_clicked()
{
    clearsheet();
    sqlQuery = QSqlQuery(database);
    sqlSelect = QString("SELECT * FROM staff"); //* 代表所有字段的信息
    if(!sqlQuery.exec(sqlSelect))
    {
          qDebug() << "Error:Failed to select record"<< database.lastError();
    }else
    {

        qDebug() << "success select record";
        //如果语句执行成功，要真正执行查询操作

        for (int i = 0;sqlQuery.next();i++)
        { //按行来进行遍历

            int id = sqlQuery.value(0).toInt();
            QString name = sqlQuery.value(1).toString();
            int age = sqlQuery.value(2).toInt();
            QString address = sqlQuery.value(3).toString();
            int salary = sqlQuery.value(4).toInt();

            qDebug() << "id" << id<< name <<"  "<< age << "  "<< address << "   " << salary;

            QTableWidgetItem *itemid = new QTableWidgetItem();
            itemid->setText(QString::number(id));
            QTableWidgetItem *itemname= new QTableWidgetItem();
            itemname->setText(name);
            QTableWidgetItem *itemage = new QTableWidgetItem();
            itemage->setText(QString::number(age));
            QTableWidgetItem *itemaddress = new QTableWidgetItem();
            itemaddress->setText(address);
            QTableWidgetItem *itemsalary = new QTableWidgetItem();
            itemsalary->setText(QString::number(salary));

            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,itemid);
            ui->tableWidget->setItem(i,1,itemname);
            ui->tableWidget->setItem(i,2,itemage);
            ui->tableWidget->setItem(i,3,itemaddress);
            ui->tableWidget->setItem(i,4,itemsalary);

        }
    }
}





void staffsystem::on_tableWidget_itemActivated(QTableWidgetItem *item)
{
//    sqlQuery = QSqlQuery(database);
//    int row = ui->tableWidget->currentRow();
//    QString id = ui->tableWidget->item(row,0)->text();
//    QString name = ui->tableWidget->item(row,1)->text();
//    QString age = ui->tableWidget->item(row,2)->text();
//    QString address = ui->tableWidget->item(row,3)->text();
//    QString salary = ui->tableWidget->item(row,4)->text();
//    qDebug() << "id" << id<< name <<"  "<< age << "  "<< address << "   " << salary;
//    sqlupdate = QString("update staff "
//                        "set id=%1,name = '%2',age=%3,address='%4',salary=%5 "
//                        "where id = %6").arg(id,name,age,address,salary,id);
//    qDebug() << salary;
//    sqlQuery.exec(sqlupdate);

//    readdb();
    qDebug() << "activated";
}

void staffsystem::on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
    qDebug() << "current_itemchangge";
}


void staffsystem::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    qDebug() << "current_cellchangge";
}

void staffsystem::on_tableWidget_itemEntered(QTableWidgetItem *item)
{
    qDebug() << "itementered";
}

void staffsystem::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
//        sqlQuery = QSqlQuery(database);
//        int row = ui->tableWidget->currentRow();
//        QString id = ui->tableWidget->item(row,0)->text();
//        QString name = ui->tableWidget->item(row,1)->text();
//        QString age = ui->tableWidget->item(row,2)->text();
//        QString address = ui->tableWidget->item(row,3)->text();
//        QString salary = ui->tableWidget->item(row,4)->text();
//        qDebug() << "id" << id<< name <<"  "<< age << "  "<< address << "   " << salary;
//        sqlupdate = QString("update staff "
//                            "set id=%1,name = '%2',age=%3,address='%4',salary=%5 "
//                            "where id = %6").arg(id,name,age,address,salary,id);
//        qDebug() << salary;
//        sqlQuery.exec(sqlupdate);

//        readdb();
//    qDebug() << "itemchangge";
}
