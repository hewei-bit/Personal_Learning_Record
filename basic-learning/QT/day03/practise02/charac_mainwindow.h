#ifndef CHARAC_MAINWINDOW_H
#define CHARAC_MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QRadioButton>

namespace Ui {
class charac_MainWindow;
}

class charac_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit charac_MainWindow(QWidget *parent = nullptr);
    ~charac_MainWindow();
public slots:
    void onhobbyRadioChecked();

private:
    Ui::charac_MainWindow *ui;
    QButtonGroup* btnGroupHobby;
};

#endif // CHARAC_MAINWINDOW_H
