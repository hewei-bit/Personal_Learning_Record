#include "file_information.h"
#include "ui_file_information.h"

file_information::file_information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::file_information)
{
    ui->setupUi(this);
    this->resize(this->width(),this->height());
}

void file_information::setDir(QString dirName)
{
    QPixmap map(":/favicon.ico");
      ui->pic_label->setPixmap(map);
      ui->name_label->setText(dirName);
}

void file_information::setFile(QString fileName, qint64 fileSize)
{
    QPixmap map(":/favicon (1).ico");
    ui->pic_label->setPixmap(map);
    ui->name_label->setText(fileName);
    ui->size_label->setText(QString::number(fileSize));
}

file_information::~file_information()
{
    delete ui;
}

void file_information::show_file_info(QFileInfo fileinfo)
{

    ui->name_label->setText(fileinfo.fileName());
    qDebug() << fileinfo.fileName();
    int size = fileinfo.size()/1024;
    QString ssize = QString("%1kb").arg(size);
    ui->size_label->setText(ssize);
    qDebug() << fileinfo.size();
}
void file_information::show_file_info_1(QFileInfo fileinfo)
{

    ui->name_label->setText(fileinfo.fileName());
    qDebug() << fileinfo.fileName();
}
