#include "form.h"
#include "ui_form.h"


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->resize(this->width(),this->height());
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
      qDebug() << "void Form::on_pushButton_clicked()";
}
