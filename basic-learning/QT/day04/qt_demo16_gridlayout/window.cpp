#include "window.h"
#include <QGridLayout>
#include <QRadioButton>
#include <QVBoxLayout>
Window::Window(QWidget *parent)
    : QWidget(parent)
{

    //[1] 由于这个窗口本身就是QWidget，那么直接给这个窗口设置布局就可以了
    QGridLayout* grid = new QGridLayout;
    grid->addWidget(createfirstGroup(),0,0);//增加一个控件到布局中，控件可以是单个组件也可以是容器
    grid->addWidget(createsecondGroup(),0,1);
    this->setLayout(grid);
}

Window::~Window()
{

}

QGroupBox *Window::createfirstGroup()
{
    QGroupBox* groupBox = new QGroupBox("second Group");

    QRadioButton* radio1 = new QRadioButton("radio Button1");
     QRadioButton* radio2 = new QRadioButton("radio Button2");
      QRadioButton* radio3 = new QRadioButton("radio Button3");
       QRadioButton* radio4 = new QRadioButton("radio Button4");
       radio1->setChecked(true);

       QVBoxLayout* vbox = new QVBoxLayout;
       vbox->addWidget(radio1);
       vbox->addWidget(radio2);
       vbox->addWidget(radio3);
       vbox->addWidget(radio4);

       groupBox->setLayout(vbox);

       return  groupBox;
}

QGroupBox *Window::createsecondGroup()
{
    QGroupBox* groupBox = new QGroupBox("first Group");

    QRadioButton* radio1 = new QRadioButton("A");
     QRadioButton* radio2 = new QRadioButton("B");
      QRadioButton* radio3 = new QRadioButton("C");
       QRadioButton* radio4 = new QRadioButton("D");
       radio1->setChecked(true);

       QVBoxLayout* vbox = new QVBoxLayout;
       vbox->addWidget(radio1);
       vbox->addWidget(radio2);
       vbox->addWidget(radio3);
       vbox->addWidget(radio4);

       groupBox->setLayout(vbox);

       return  groupBox;
}
