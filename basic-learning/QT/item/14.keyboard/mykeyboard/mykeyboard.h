#ifndef MYKEYBOARD_H
#define MYKEYBOARD_H

#include <QMainWindow>

namespace Ui {
class mykeyboard;
}

class mykeyboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit mykeyboard(QWidget *parent = nullptr);
    ~mykeyboard();

private:
    Ui::mykeyboard *ui;
};

#endif // MYKEYBOARD_H
