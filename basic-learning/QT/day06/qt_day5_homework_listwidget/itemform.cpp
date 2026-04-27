#include "itemform.h"
#include "ui_itemform.h"

ItemForm::ItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemForm)
{
    ui->setupUi(this);
    this->resize(this->width(),this->height());
}

ItemForm::~ItemForm()
{
    delete ui;
}

void ItemForm::setDir(QString dirName)
{
  QPixmap map(":/pic/dir.png");
    ui->picLabel->setPixmap(map);
    ui->fileNameLabel->setText(dirName);
}

void ItemForm::setFile(QString fileName, qint64 fileSize)
{
      QPixmap map(":/pic/file.png");
      ui->picLabel->setPixmap(map);
      ui->fileNameLabel->setText(fileName);
      ui->fileSizeLabel->setText(QString::number(fileSize));
}
