#include "imagebrowsing.h"
#include "ui_imagebrowsing.h"

Imagebrowsing::Imagebrowsing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Imagebrowsing)
{
    ui->setupUi(this);
}

Imagebrowsing::~Imagebrowsing()
{
    delete ui;
}

void Imagebrowsing::on_browseBtn_clicked()
{
       QStringList namefiles =  QFileDialog::getOpenFileNames(this);

       ui->listWidget->addItems(namefiles);
}

void Imagebrowsing::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
         QString namefile = item->text();

//         QFile file(namefile);

//         if(!file.open(QIODevice::ReadOnly))
//         {
//             qDebug() << " open file failed";
//         }

//         QByteArray data = file.readAll();
         QPixmap map(namefile);
         map = map.scaled(ui->picLabel->width(),ui->picLabel->height());
         ui->picLabel->setPixmap(map);
}
