#include "teachermainwindow.h"
#include "ui_teachermainwindow.h"

TeacherMainWindow::TeacherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherMainWindow)
{
    ui->setupUi(this);
}

TeacherMainWindow::~TeacherMainWindow()
{
    delete ui;
}

void TeacherMainWindow::getTeacher(Teacher t)
{

}

void TeacherMainWindow::getTeacherInfo(Teacher teacher)
{
        // t1  = teacher;
        ui->nameLabel->setText(QString::fromStdString(teacher.name()));
        ui->departmentLabel->setText(QString::fromStdString(teacher.department()));
        ui->dutyLabel->setText(QString::fromStdString(teacher.duty()));
        getTeacher(teacher);
}

void TeacherMainWindow::getModefiedTeacher(Teacher t)
{
    ui->nameLabel->setText(QString::fromStdString(t.name()));
    ui->departmentLabel->setText(QString::fromStdString(t.department()));
    ui->dutyLabel->setText(QString::fromStdString(t.duty()));
}




void TeacherMainWindow::on_setBtn_clicked()
{
       //进行设置界面
       SetTeahcerWin * stw = new SetTeahcerWin(this); //告诉系统，从哪一个界面开始跳转到设置界面
       stw->show();
       this->hide();
}
