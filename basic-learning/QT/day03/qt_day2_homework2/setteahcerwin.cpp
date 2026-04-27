#include "setteahcerwin.h"
#include "ui_setteahcerwin.h"
#include "teachermainwindow.h"
SetTeahcerWin::SetTeahcerWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetTeahcerWin)
{
    ui->setupUi(this);
}

SetTeahcerWin::~SetTeahcerWin()
{
    delete ui;
}

void SetTeahcerWin::on_backBtn_clicked()
{
   //方法二
    TeacherMainWindow* tmw = new TeacherMainWindow;
     //方法一
//     //this->parentWidget()->show(); 显示父窗口
   QString name =  ui->namesetEdit->text();
   //QString ---- >string
    Teacher t(name.toStdString(),ui->departemntsetEdit->text().toStdString(),
              ui->dutySetEdit->text().toStdString());

   // connect(this,&SetTeahcerWin::sendTeacherModifed,
   //         static_cast<TeacherMainWindow*>(this->parentWidget()),&TeacherMainWindow::getModefiedTeacher);
    connect(this,&SetTeahcerWin::sendTeacherModifed,
            tmw,&TeacherMainWindow::getModefiedTeacher);
    emit sendTeacherModifed(t);
    //this->parentWidget()->show(); //返回值为QWidget *，但是实际上的界面是TeacherMainWindow
     tmw->show();
    this->close();

}
