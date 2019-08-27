#include "mainview.h"
#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

Player * _player;
QTimer * _timer;

MainView::MainView(QGraphicsScene * scene, Player * player, QTimer * timer) : QGraphicsView(scene)
{
    _player = player;
    _timer = timer;
}

