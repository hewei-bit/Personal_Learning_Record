#ifndef QMPLAYER_H
#define QMPLAYER_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QProcess>




namespace Ui {
class Qmplayer;
}

class Qmplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Qmplayer(QWidget *parent = nullptr);
    ~Qmplayer();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_addBtn_clicked();

private:
    Ui::Qmplayer *ui;
    QProcess mprocess;
};

#endif // QMPLAYER_H
