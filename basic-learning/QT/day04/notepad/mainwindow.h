#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDialog>
#include <QFont>
#include <QtDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>

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
    void on_open_Btn_clicked();

    void on_save_Btn_clicked();

    void on_set_font_Btn_clicked();

    void on_set_background_Btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
