#include "mykeyboard.h"
#include "ui_mykeyboard.h"

mykeyboard::mykeyboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mykeyboard)
{
    ui->setupUi(this);
}

mykeyboard::~mykeyboard()
{
    delete ui;
}
