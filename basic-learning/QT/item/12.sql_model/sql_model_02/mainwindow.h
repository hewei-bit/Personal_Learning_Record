#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQuery>
#include <QFile>


namespace Ui {
class MainWindow;
}

class runningTimer : public QMainWindow
{
    Q_OBJECT

public:
    explicit runningTimer(QWidget *parent = nullptr);
    ~runningTimer();

    bool opendatabase();

    void insertdata();

    void iscreateDatabaseTable();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QFile file;
    bool isCreateTable; //表是否创建

};

#endif // MAINWINDOW_H
