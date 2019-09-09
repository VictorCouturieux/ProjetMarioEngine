
#include <QApplication>
#include <QLabel>
#include <QMediaPlayer>

#include "mainwin.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWin mainWin;
    mainWin.setSize();

    QMediaPlayer *level1 = new QMediaPlayer;
    level1->setMedia(QUrl("qrc:/sounds/level1.mp3"));
    level1->play();

    mainWin.show();

    return a.exec();

}

