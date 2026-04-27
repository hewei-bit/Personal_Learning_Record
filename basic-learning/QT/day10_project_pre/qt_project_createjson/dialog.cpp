#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("新建收银员");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showEvent(QShowEvent *)
{
    ui->acLe->clear();
    ui->pwLe->clear();
}

void Dialog::on_buttonBox_accepted()
{
    QStringList list;
    list << ui->acLe->text() << ui->pwLe->text();
    emit finish(list);
    this->close();
}

void Dialog::on_buttonBox_rejected()
{
    this->hide();
}
