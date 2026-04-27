#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H

#include <QMainWindow>

namespace Ui {
class MainSystem;
}

class MainSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSystem(QWidget *parent = nullptr);
    ~MainSystem();

private:
    Ui::MainSystem *ui;
};

#endif // MAINSYSTEM_H
