#ifndef FLAG_H
#define FLAG_H

#include <QGraphicsItem>
#include <QPixmap>

const int flagType = 12;

class Flag : public QGraphicsItem
{
public:
    enum {Type = UserType + flagType};
    Flag(QGraphicsItem *parent = 0);
    void nextFrame();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;

private:
    int mCurrentFrame;
    QPixmap mPixmap8;

};

#endif // FLAG_H
