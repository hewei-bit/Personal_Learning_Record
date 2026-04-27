#include "charac_mainwindow.h"
#include "ui_charac_mainwindow.h"
#include <QtDebug>

charac_MainWindow::charac_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::charac_MainWindow)
{
    ui->setupUi(this);

    btnGroupHobby = new QButtonGroup(this);
    btnGroupHobby->addButton(ui->gameBtn,0);
    btnGroupHobby->addButton(ui->musicBtn,1);
    btnGroupHobby->addButton(ui->sportBtn,2);

    connect(ui->gameBtn,&QRadioButton::clicked,this,&charac_MainWindow::onhobbyRadioChecked);
    connect(ui->musicBtn,&QRadioButton::clicked,this,&charac_MainWindow::onhobbyRadioChecked);
    connect(ui->sportBtn,&QRadioButton::clicked,this,&charac_MainWindow::onhobbyRadioChecked);

}

charac_MainWindow::~charac_MainWindow()
{
    delete ui;
}

void charac_MainWindow::onhobbyRadioChecked()
{
    qDebug() << ui->gameBtn->isChecked();
    qDebug() << ui->musicBtn->isChecked();
    qDebug() << ui->sportBtn->isChecked();

   int checkId =  btnGroupHobby->checkedId();
   switch (checkId) {
    case 0:
       qDebug() << "你选择了做音乐";
       break;
    case 1:
       qDebug() << "你选择了做游戏";
       break;
   case 2:
      qDebug() << "你选择了做人生";
      break;
    case -1:
       qDebug() << "你不选择做女人，也不选择做男人";
       break;
   }
}
