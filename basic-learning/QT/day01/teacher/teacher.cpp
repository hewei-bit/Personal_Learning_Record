#include "teacher.h"
#include "ui_teacher.h"
#include <QString>
//teacher::teacher(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::teacher)
//{
//    ui->setupUi(this);

//}

teacher::teacher(QWidget *parent, string name, int num, string sex, int age):
    QMainWindow(parent),
    ui(new Ui::teacher),
    name(name),num(num),sex(sex),age(age)
{
    ui->setupUi(this);
//    ui->name_textBrowser->setText(QString::fromStdString(this->name));
    ui->name_label->setText(QString::fromStdString(this->name));
}

teacher::~teacher()
{
    delete ui;
}
