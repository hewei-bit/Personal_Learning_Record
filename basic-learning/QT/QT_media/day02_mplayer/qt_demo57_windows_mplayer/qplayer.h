#ifndef QPLAYER_H
#define QPLAYER_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QProcess>
namespace Ui {
class QPlayer;
}

class QPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QPlayer(QWidget *parent = nullptr);
    ~QPlayer();

private slots:
    void on_addBtn_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::QPlayer *ui;
    QProcess mProcess;
};

#endif // QPLAYER_H
