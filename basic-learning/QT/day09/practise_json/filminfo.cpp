#include "filminfo.h"
#include "ui_filminfo.h"

filminfo::filminfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::filminfo)
{
    ui->setupUi(this);
}

filminfo::~filminfo()
{
    delete ui;
}

void filminfo::showinfo(QJsonObject film_info)
{
    ui->rating_textBrowser->setText(film_info.value("rating").toString());
    ui->name_textBrowser_2->setText(film_info.value("title").toString());
}
