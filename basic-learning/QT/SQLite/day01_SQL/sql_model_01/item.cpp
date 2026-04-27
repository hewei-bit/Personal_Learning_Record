#include "item.h"
#include "ui_item.h"

item::item(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::item)
{
    ui->setupUi(this);
}

item::~item()
{
    delete ui;
}
