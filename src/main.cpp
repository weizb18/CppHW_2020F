#include <QtGui/QApplication>
#include "mainwindow.h"
#include "initialize.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    initialWeizibu();

    MainWindow w;
    w.show();

    return a.exec();
}
