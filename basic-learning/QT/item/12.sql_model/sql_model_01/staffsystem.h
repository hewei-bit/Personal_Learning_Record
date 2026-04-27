#ifndef STAFFSYSTEM_H
#define STAFFSYSTEM_H

#include <QMainWindow>
#include <QSqlDatabase> //数据库对象类
#include <QSqlQuery>
#include <QTableWidgetItem>
namespace Ui {
class staffsystem;
}

class staffsystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit staffsystem(QWidget *parent = nullptr);
    ~staffsystem();

private slots:
    void on_add_Btn_clicked();

    void on_renew_Btn_clicked();

    void on_delete_Btn_clicked();

    void on_check_Btn_clicked();

    bool open();

    void clearsheet();

    void readdb();

    void on_tableWidget_itemActivated(QTableWidgetItem *item);

    void on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_tableWidget_itemEntered(QTableWidgetItem *item);

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::staffsystem *ui;
    QSqlDatabase database;
    QSqlQuery sqlQuery;
    QString sqlSelect;
    QString sqlInsert;
    QString sqlupdate;
    QString sqldelete;
};

#endif // STAFFSYSTEM_H
