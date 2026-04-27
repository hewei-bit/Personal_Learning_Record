#include "teacherwindow.h"
#include "ui_teacherwindow.h"

void TeacherWindow::initTeacher()
{
    teacher = new Teacher("张三",100,"M",30);
    //QString  <----> string
    // static QString fromStdString(const std::string &str)

    ui->nameLabel->setText(QString::fromStdString(teacher->name()));
    //QString --> int
    // static QString number(int n, int base = 10) 10-->十进制

    ui->noLabel->setText(QString::number(teacher->no()));

    ui->sexLabel->setText(QString::fromStdString(teacher->sex()));
     ui->ageLabel->setText(QString::number(teacher->age()));

}

TeacherWindow::TeacherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);

    initTeacher();

}

TeacherWindow::~TeacherWindow()
{
    delete ui;
    delete teacher;
}
