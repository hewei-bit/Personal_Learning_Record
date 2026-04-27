#include "welcome.h"
#include "ui_welcome.h"

welcome::welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);

}

void welcome::showname(QString s)
{
    ui->user->setText(s);
}


welcome::~welcome()
{
    delete ui;
}
