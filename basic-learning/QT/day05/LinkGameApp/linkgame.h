#ifndef LINKGAME_H
#define LINKGAME_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class LinkGame;
}

class LinkGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit LinkGame(QWidget *parent = nullptr);
    ~LinkGame();
private slots:
    void buttonClicked();
private:
    Ui::LinkGame *ui;

    QPushButton* buttons[4][4];
};

#endif // LINKGAME_H
