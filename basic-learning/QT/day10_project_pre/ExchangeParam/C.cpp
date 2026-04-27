#include "C.h"
#include "ui_C.h"

C::C(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::C)
{
    ui->setupUi(this);

    //按钮信号
    connect(ui->toA,SIGNAL(clicked(bool)),this,SLOT(pushA()));
    connect(ui->toB,SIGNAL(clicked(bool)),this,SLOT(pushB()));
}

C::~C()
{
    delete ui;
}

void C::fromA(QString data)
{
    ui->Cshow->append(data);
}

void C::fromB(QString data)
{
    ui->Cshow->append(data);
}

void C::pushA()
{
    emit toA(ui->toAdata->text());
}

void C::pushB()
{
    emit toB(ui->toBdata->text());
}
