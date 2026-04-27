#include "qsqliteoperator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QsqliteOperator w;
    w.show();

    return a.exec();
}
