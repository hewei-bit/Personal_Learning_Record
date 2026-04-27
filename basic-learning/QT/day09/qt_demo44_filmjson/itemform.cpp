#include "itemform.h"
#include "ui_itemform.h"
#include <QtDebug>

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

void ItemForm::setFilmInfo(QString rating, QString genres,
                           QString runtime, QString language,
                           QString title, QString year, QString country,
                           QString rating_count, QString actors,QString directors)
{
   ui->ratingLabel->setText(rating);
   ui->genresLabel->setText(genres);
   ui->runtimeLabel->setText(runtime);
   ui->languageLabel->setText(language);
   ui->titleLabel->setText(title);
   ui->yearLabel->setText(year);
   ui->countryLabel->setText(country);
   ui->rating_countLabel->setText(rating_count);
   ui->actorsLabel->setText(actors);
   ui->directorsLabel->setText(directors);

}

void ItemForm::getPicData(const QByteArray &data)
{
    QPixmap map;
   bool ok =  map.loadFromData(data);
   qDebug() << "ok = " << ok;
   ui->picLabel->setPixmap(map);
}
