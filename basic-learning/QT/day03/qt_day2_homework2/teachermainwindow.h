#ifndef TEACHERMAINWINDOW_H
#define TEACHERMAINWINDOW_H

#include <QMainWindow>
#include "teacher.h"
#include "setteahcerwin.h"

namespace Ui {
class TeacherMainWindow;
}

class TeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainWindow(QWidget *parent = nullptr);
    ~TeacherMainWindow();
   void getTeacher(Teacher t);
public slots:
    void getTeacherInfo(Teacher teacher);
    //得到修改后的教师信息
    void getModefiedTeacher(Teacher t);
private slots:
    void on_setBtn_clicked();

private:
    Teacher t1;
    Ui::TeacherMainWindow *ui;
};

#endif // TEACHERMAINWINDOW_H
