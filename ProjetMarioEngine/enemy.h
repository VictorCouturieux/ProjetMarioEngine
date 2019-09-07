#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>

#include <typeinfo>

const int goombaType = 4;

class Enemy :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum { Type = UserType + goombaType };
    Enemy(QRectF platformRect, int direction, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;

public slots:
    void nextFrame();

signals:
    void marioStatus(int);

private:
    int mCurrentFrame;
    QPixmap mPixmap;
    QRectF mplateau;
    int mDirection;

};

#endif // ENEMY_H
