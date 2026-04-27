#ifndef SHOW_LIST_H
#define SHOW_LIST_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtDebug>
#include <QFileDialog>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class show_list;
}

class show_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_list(QWidget *parent = nullptr);
    ~show_list();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_actionopen_triggered();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::show_list *ui;

    QStringList  filePath;
};

#endif // SHOW_LIST_H
