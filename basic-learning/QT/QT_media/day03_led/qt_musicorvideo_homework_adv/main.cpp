#include "qdvwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QdvWidget w;
    w.show();

    return a.exec();
}
