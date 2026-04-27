#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase> //数据库对象类
namespace Ui {
class StaffWindow;
}

class StaffWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaffWindow(QWidget *parent = nullptr);
    ~StaffWindow();

private slots:
    void on_selectBtn_clicked();

    void on_delBtn_clicked();

    void on_addBtn_clicked();

    void on_updateBtn_clicked();

private:
    Ui::StaffWindow *ui;
    QSqlDatabase database;
};

#endif // STAFFWINDOW_H
