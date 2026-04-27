#include "A.h"
#include "ui_A.h"

A::A(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::A)
{
    ui->setupUi(this);

    b=new B;
    c=new C;
    b->show();
    c->show();
    b->setWindowTitle("B");
    c->setWindowTitle("C");
    b->move(this->x()+200,this->y());
    c->move(this->x()+800,this->y());

    //B向C发送数据
    connect(b,SIGNAL(toC(QString)),c,SLOT(fromB(QString)));
    //C向B发送数据
    connect(c,SIGNAL(toB(QString)),b,SLOT(fromC(QString)));

    //B向A发送数据
    connect(b,SIGNAL(toA(QString)),this,SLOT(fromB(QString)));
    //C向A发送数据
    connect(c,SIGNAL(toA(QString)),this,SLOT(fromC(QString)));

    //按钮信号
    connect(ui->toB,SIGNAL(clicked(bool)),this,SLOT(pushB()));
    connect(ui->toC,SIGNAL(clicked(bool)),this,SLOT(pushC()));

}

void A::closeEvent(QCloseEvent *event)
{
    qApp->quit();
}

A::~A()
{
    delete ui;
    delete b;
    delete c;
}

void A::fromB(QString data)
{
    ui->Ashow->append(data);
}

void A::fromC(QString data)
{
    ui->Ashow->append(data);
}

void A::pushB()
{
    b->fromA(ui->toBdata->text());
}

void A::pushC()
{
    c->fromA(ui->toCdata->text());
}
