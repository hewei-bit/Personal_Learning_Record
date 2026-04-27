#ifndef ITEM_H
#define ITEM_H

#include <QMainWindow>

namespace Ui {
class item;
}

class item : public QMainWindow
{
    Q_OBJECT

public:
    explicit item(QWidget *parent = nullptr);
    ~item();

private:
    Ui::item *ui;
};

#endif // ITEM_H
