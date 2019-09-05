#include "warptube.h"

#include <QPainter>
#include <QDebug>

WarpTube::WarpTube(QGraphicsItem * parent) :
    QGraphicsItem (parent)
  , mCurrentFrame()
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
    return QRectF(0,0,140,256);
}

void WarpTube::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0, 140, 256);
    setTransformOriginPoint((boundingRect().center()));
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

int WarpTube::type() const{
    return Type;
}
