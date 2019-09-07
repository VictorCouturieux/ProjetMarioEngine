#ifndef WARPTUBE_H
#define WARPTUBE_H

#include <QObject>
#include <QGraphicsItem>

const int warpTubeType = 13;

class WarpTube : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum { Type = UserType + warpTubeType };
    WarpTube( QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    int type() const;
    void handleCollosionGoomba();
    void nextFrame();
    QPointF getPosBoundingRect();

private:

    int sizeX;
    int sizeY;
    int mCurrentFrame;
    QPixmap mPixmap;
    QRectF mPlatform;
    int mDirection;

};

#endif // WARPTUBE_H
