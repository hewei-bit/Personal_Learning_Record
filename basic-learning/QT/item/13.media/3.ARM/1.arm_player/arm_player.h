#ifndef ARM_PLAYER_H
#define ARM_PLAYER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtDebug>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QProcess>

namespace Ui {
class ARM_player;
}

class ARM_player : public QMainWindow
{
    Q_OBJECT

public:
    explicit ARM_player(QWidget *parent = nullptr);
    ~ARM_player();

private slots:
    void on_addBtn_clicked();

private:
    Ui::ARM_player *ui;
    QProcess mProcess;
};

#endif // ARM_PLAYER_H
