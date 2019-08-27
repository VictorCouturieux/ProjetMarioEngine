#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent * event);
public:
    void keyReleaseEvent(QKeyEvent * event);
public slots:
    void goPlayer();

};

#endif // PLAYER_H
