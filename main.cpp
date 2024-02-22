#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // згодом може бути іконка для додатку
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
