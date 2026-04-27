#ifndef TEACHERSYSTEM_H
#define TEACHERSYSTEM_H

#include <QMainWindow>
#include "teacher.h"
#include "teachermainwindow.h"

namespace Ui {
class TeacherSystem;
}

class TeacherSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherSystem(QWidget *parent = nullptr);
    ~TeacherSystem();
signals:
    void sendTeacherInfo(Teacher teacher);
private slots:
    void on_teacherBtn_clicked();


private:
    Ui::TeacherSystem *ui;
};

#endif // TEACHERSYSTEM_H
