#include "mainwindow.h"
#include "listoptions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListOptions w;
    //MainWindow w;
    w.show();

    return a.exec();
}
