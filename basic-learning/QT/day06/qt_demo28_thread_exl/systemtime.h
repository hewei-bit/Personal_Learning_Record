#ifndef SYSTEMTIME_H
#define SYSTEMTIME_H

#include <QMainWindow>
#include "systemtimethread.h"

namespace Ui {
class SystemTime;
}

class SystemTime : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemTime(QWidget *parent = nullptr);
    ~SystemTime();
private slots:
    void updateSystemTime();
private:
    Ui::SystemTime *ui;
    systemTimeThread* systemtimeth;
};

#endif // SYSTEMTIME_H
