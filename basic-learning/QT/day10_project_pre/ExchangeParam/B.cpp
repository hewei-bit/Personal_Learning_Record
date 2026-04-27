#include "B.h"
#include "ui_B.h"

B::B(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::B)
{
    ui->setupUi(this);

    //按钮信号
    connect(ui->toA,SIGNAL(clicked(bool)),this,SLOT(pushA()));
    connect(ui->toC,SIGNAL(clicked(bool)),this,SLOT(pushC()));
}

B::~B()
{
    delete ui;
}

void B::fromA(QString data)
{
    ui->Bshow->append(data);
}

void B::fromC(QString data)
{
    ui->Bshow->append(data);
}

void B::pushA()
{
    emit toA(ui->toAdata->text());
}

void B::pushC()
{
    emit toC(ui->toCdata->text());
}
