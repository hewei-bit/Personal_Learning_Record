#ifndef STUDENTITEM_H
#define STUDENTITEM_H

#include <QMainWindow>

namespace Ui {
class studentItem;
}

class studentItem : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentItem(QWidget *parent = nullptr);
    ~studentItem();
     void setStudentInfo(const QString& name,int age,const QString& addr);
private:
    Ui::studentItem *ui;
};

#endif // STUDENTITEM_H
