#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QGroupBox>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();
    QGroupBox* createfirstGroup();

     QGroupBox* createsecondGroup();
};

#endif // WINDOW_H
