#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_actionbackgroud_triggered();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionfont_triggered();

    void on_actionabout_notepad_triggered();

    void on_plainTextEdit_cursorPositionChanged();

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
