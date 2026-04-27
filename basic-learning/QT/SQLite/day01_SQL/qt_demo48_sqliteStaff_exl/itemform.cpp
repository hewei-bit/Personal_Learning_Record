#include "itemform.h"
#include "ui_itemform.h"

itemform::itemform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::itemform)
{
    ui->setupUi(this);
    this->setFixedSize(844,44);
}

itemform::~itemform()
{
    delete ui;
}

void itemform::setItem(int id, QString name, int age, QString addr, int salary)
{
    ui->idLabel->setText(QString::number(id));
    ui->nameLabel->setText(name);
    ui->ageLabel->setText(QString::number(age));
    ui->addrLabel->setText(addr);
    ui->salaryLabel->setText(QString::number(salary));
}
