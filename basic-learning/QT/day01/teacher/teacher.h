#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <QMainWindow>
using namespace std;

namespace Ui {
class teacher;
}

class teacher : public QMainWindow
{
    Q_OBJECT

public:
//    explicit teacher(QWidget *parent = nullptr);
    teacher(QWidget *parent = nullptr,string name = "ming",int num = 1,string sex = "male",int age = 33);
    ~teacher();

private:
    Ui::teacher *ui;
    string name;
    int num;
    string sex;
    int age;
};

#endif // TEACHER_H
