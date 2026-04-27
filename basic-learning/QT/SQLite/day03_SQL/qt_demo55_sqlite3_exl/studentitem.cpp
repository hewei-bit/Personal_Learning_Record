#include "studentitem.h"
#include "ui_studentitem.h"

studentItem::studentItem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studentItem)
{
    ui->setupUi(this);
    this->setFixedSize(583,39);
}

studentItem::~studentItem()
{
    delete ui;
}

void studentItem::setStudentInfo(const QString &name, int age, const QString &addr)
{
    ui->nameLabel->setText(name);
    ui->ageLabel->setText(QString::number(age));
    ui->addrLabel->setText(addr);
}
