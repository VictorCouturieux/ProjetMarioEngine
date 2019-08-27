#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "player.h"

#include <QGraphicsView>
#include <QObject>
#include <QTimer>

class MainView: public QGraphicsView
{
public:
    MainView(QGraphicsScene * scene, Player * player, QTimer * timer);
};

#endif // MAINVIEW_H
