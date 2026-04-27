#ifndef IMAGEBROWSING_H
#define IMAGEBROWSING_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
namespace Ui {
class Imagebrowsing;
}

class Imagebrowsing : public QMainWindow
{
    Q_OBJECT

public:
    explicit Imagebrowsing(QWidget *parent = nullptr);
    ~Imagebrowsing();

private slots:
    void on_browseBtn_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Imagebrowsing *ui;
};

#endif // IMAGEBROWSING_H
