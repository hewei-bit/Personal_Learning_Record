#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include <QMap>
#include <QFile>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createJsonData();

private slots:
    void on_getBtn_clicked();
    void getNewMember(QStringList list); //增加新员工
    void on_addStaffBtn_clicked();

    void on_delStaffBtn_clicked();

    void on_backBtn_clicked();

    void on_saveBtn_clicked();

    void on_staffTableWidget_itemChanged(QTableWidgetItem *item);

    void on_staffTableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    bool isChange; //账户信息是否改变
    QString begin; //如果账户信息发生改变，则表示第一个
    Dialog *dialog;
    QMap<QString,QString> account; //key -value
    QFile accountFile;
};

#endif // MAINWINDOW_H
