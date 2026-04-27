#ifndef ITEMFORM_H
#define ITEMFORM_H

#include <QWidget>

namespace Ui {
class ItemForm;
}
//QString rating = objectArray.value("rating").toString();
//QString genres = objectArray.value("genres").toString();
//QString runtime = objectArray.value("runtime").toString();
//QString language = objectArray.value("language").toString();
//QString title = objectArray.value("title").toString();
//QString poster = objectArray.value("poster").toString();
//QString year = objectArray.value("year").toString();

//QString country = objectArray.value("country").toString();
//QString directors = objectArray.value("directors").toString();
//QString rating_count = objectArray.value("rating_count").toString();
//QString actors = objectArray.value("actors").toString();
class ItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit ItemForm(QWidget *parent = nullptr);
    ~ItemForm();
    void setFilmInfo(QString rating,QString genres,QString runtime
                     ,QString language,QString title,
                     QString year,QString country,
                     QString rating_count,
                     QString actors,QString directors);

public slots:
    void getPicData(const QByteArray& data);
private:
    Ui::ItemForm *ui;
};

#endif // ITEMFORM_H
