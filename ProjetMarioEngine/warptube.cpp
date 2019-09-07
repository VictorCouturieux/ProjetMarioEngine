#include "warptube.h"

#include <QPainter>
#include <QDebug>

WarpTube::WarpTube(QGraphicsItem * parent) :
    QGraphicsItem (parent)
  , mCurrentFrame()
  , sizeX(140)
  , sizeY(256)
{
    setFlag(ItemClipsToShape);
     mPixmap = QPixmap(":/images/warpTube2.png");
}

void WarpTube::nextFrame(){
    mCurrentFrame += 54;
    if (mCurrentFrame>= 862){
        mCurrentFrame = 0;
    }
}

QRectF WarpTube:: boundingRect() const{
    return QRectF(0,0,sizeX,sizeY);
}

void WarpTube::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0, sizeX, sizeY);
    setTransformOriginPoint((boundingRect().center()));
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

int WarpTube::type() const{
    return Type;
}

QPointF WarpTube::getPosBoundingRect(){
    return QPointF(x()+sizeX, y()+sizeY);
}
