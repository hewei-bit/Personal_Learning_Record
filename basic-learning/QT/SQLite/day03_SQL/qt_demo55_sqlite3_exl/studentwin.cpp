#include "studentwin.h"
#include "ui_studentwin.h"
#include <iostream>
#include <QtDebug>
#include <QTableView>
#include "studentitem.h"
using namespace std;
StudentWin::StudentWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWin)
{
    ui->setupUi(this);

    int rc;

    rc = sqlite3_open("school.db", &db); //参数一，传入参数  参数二，传出参数
      if( rc ){
         qDebug() << "Can't open database:" << sqlite3_errmsg(db);
         sqlite3_close(db);
         return;
       }
}

StudentWin::~StudentWin()
{
    delete ui;
}
//sqlite3 与 qt 中 sql模块
void StudentWin::updateStudentInfo(QStringList students)
{
    qDebug() << "updateStudentInfo";
    for (int i=0;i<students.size();i++) {
      qDebug() << students[i];
    }


   QTableView * view = new QTableView;
   view->show();
}

//sqlite3 函数回调，不是定义为类的成员函数，因为它是由sqlite3_exec执行sql语句自动调用
int callback(void* data ,int col,char** value,char** name)
{
   // qDebug() << "col = "<< col;
    QStringList names;
    for(int i =0;i<col;i++)
    {
       // qDebug() << *(value + i);
       // qDebug() << *(name + i);
        names << *(value + i);
    }

    qDebug() << names;
    //创建学生类：name age addr
   // StudentWin::updateStudentInfo(names);
    // ui->ageEdit->setText("asff");

   StudentWin* sw =  static_cast< StudentWin*>(QApplication::activeWindow());
   qDebug() << sw;

   studentItem* itemform = new studentItem;
   itemform->setStudentInfo(names[0],names[1].toInt(),names[2]);

   QListWidgetItem* item = new QListWidgetItem;
   item->setSizeHint(QSize(583,39));

   sw->ui->listWidget->addItem(item);
   sw->ui->listWidget->setItemWidget(item,itemform);

     return  0; //返回值要设置为0，则表示执行sql语句成功
}
void StudentWin::on_selectBtn_clicked()
{
    int rc;

    rc = sqlite3_exec(db, "select * from student", callback, nullptr,nullptr);
    if( rc!=SQLITE_OK ){
        qDebug()<<"SQL error:";

      }

}

void StudentWin::on_addBtn_clicked()
{
    int rc;
    QString sql = QString("INSERT INTO student(name,age,addr) "
                          "VALUES('%1',%2,'%3');")
                            .arg(ui->nameEdit->text())
                            .arg(ui->ageEdit->text())
                            .arg(ui->addrEdit->text());
    string str = sql.toStdString();
    rc = sqlite3_exec(db, str.c_str(), nullptr, nullptr,nullptr);
    if( rc!=SQLITE_OK ){
        qDebug()<<"SQL error:";

      }
}
