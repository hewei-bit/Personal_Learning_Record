#ifndef QSQLITEOPERATOR_H
#define QSQLITEOPERATOR_H

#include <QMainWindow>
#include <QSqlDatabase> //数据库对象类

namespace Ui {
class QsqliteOperator;
}

class QsqliteOperator : public QMainWindow
{
    Q_OBJECT

public:
    explicit QsqliteOperator(QWidget *parent = nullptr);
    ~QsqliteOperator();

private:
    Ui::QsqliteOperator *ui;
};

#endif // QSQLITEOPERATOR_H
