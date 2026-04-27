#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QtDebug>
//第一步添加头文件
#include "sqlite3.h"


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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int rc;
    sqlite3 *db;
    rc = sqlite3_open("student.db",&db);
    if(rc)
    {
        qDebug() << "can't open database" << sqlite3_errmsg(db);
        sqlite3_close(db);
//        return 1;
    }

    rc = sqlite3_exec(db,"select * from studentlist",callback,nullptr,nullptr);

    if( rc!=SQLITE_OK ){
        qDebug()<<"SQL error:";

    }




    sqlite3_close(db);

//    ui->tableWidget->setItem();

}

MainWindow::~MainWindow()
{
    delete ui;
}
