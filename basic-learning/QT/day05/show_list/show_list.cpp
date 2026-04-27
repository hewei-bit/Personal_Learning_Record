#include "show_list.h"
#include "ui_show_list.h"



show_list::show_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_list)
{
    ui->setupUi(this);

    ui->listWidget->addItem("diyitiao");

}

show_list::~show_list()
{
    delete ui;
}

void show_list::on_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug() << "on_listWidget_itemClicked";
}

void show_list::on_actionopen_triggered()
{
    qDebug() << "on_actionopen_triggered";
    filePath = QFileDialog::getOpenFileNames(this);
    qDebug() << filePath;
    for (int i = 0;i < filePath.size();i++) {
        QFileInfo fileinfo(filePath.at(i));
        ui->listWidget->addItem(fileinfo.fileName());
    }
}

void show_list::on_listWidget_doubleClicked(const QModelIndex &index)
{
    qDebug() << "on_listWidget_doubleClicked";
    index.row();
    QString filename = filePath.at(index.row());
    QFile file(filename);

    bool isok = file.open(QIODevice::ReadWrite);
    if(isok)
    {
        QByteArray arr = file.readAll();
        ui->textBrowser->setText(arr);
    }
    file.close();
}

void show_list::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << "on_listWidget_itemDoubleClicked";

}
