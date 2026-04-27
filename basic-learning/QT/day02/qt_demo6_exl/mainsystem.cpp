#include "mainsystem.h"
#include "ui_mainsystem.h"

MainSystem::MainSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSystem)
{
    ui->setupUi(this);
}

MainSystem::~MainSystem()
{
    delete ui;
}
