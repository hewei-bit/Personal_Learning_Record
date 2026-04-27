#ifndef SCREENCUT_H
#define SCREENCUT_H

#include <QWidget>
#include <QTimer>
#include <QStandardPaths>
#include <QDir>
#include <QFileDialog>
#include <QImageWriter>
#include <QMessageBox>
#include <QWindow>
#include <QScreen>
namespace Ui {
class ScreenCut;
}

class ScreenCut : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenCut(QWidget *parent = nullptr);
    ~ScreenCut();
private slots:
    void newScreenshot();
    void saveScreenshot();
    void shootScreen();
    void updateCheckBox();
private:
    QPixmap originalPixmap;
    void updateScreenshotLabel();
    Ui::ScreenCut *ui;
};

#endif // SCREENCUT_H
