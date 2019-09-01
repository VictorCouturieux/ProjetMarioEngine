
#include <QApplication>
#include <QLabel>

#include "mainwin.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWin mainWin;
    mainWin.setSize();

    mainWin.show();

    return a.exec();

}

