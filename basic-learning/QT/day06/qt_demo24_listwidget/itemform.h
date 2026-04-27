#ifndef ITEMFORM_H
#define ITEMFORM_H

#include <QWidget>

namespace Ui {
class ItemForm;
}

class ItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit ItemForm(QWidget *parent = nullptr);
    ~ItemForm();
    void setDir(QString dirName);
    void setFile(QString fileName,qint64 fileSize,const QPixmap& map);
private:
    Ui::ItemForm *ui;
};

#endif // ITEMFORM_H
