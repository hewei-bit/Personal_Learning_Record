#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void doubleListWidgetClicked(QListWidgetItem *item);
private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
};

#endif // MAINWINDOW_H
