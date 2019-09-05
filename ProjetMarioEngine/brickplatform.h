#ifndef BRICKPLATFORM_H
#define BRICKPLATFORM_H

const int brickPlatformType = 2;

#include <QGraphicsItem>
#include <QPixmap>

class BrickPlatform: public QGraphicsItem
{
public:
    enum { Type = UserType + brickPlatformType };
    BrickPlatform( int length, QGraphicsItem *parent = 0);
    void nextFrame();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;

private:
    int mCurrentFrame;
    QPixmap mPixmap;
    int mLength;
    int mDirection;
};

#endif // BRICKPLATFORM_H
