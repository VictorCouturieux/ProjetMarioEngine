#include "enemy.h"
#include "player.h"
#include <QPainter>
#include <QDebug>

Enemy::Enemy(QRectF platformRect, int direction, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , mCurrentFrame()
    , mplateau(platformRect)
    , mDirection(direction)
{
    setFlag(ItemClipsToShape);
    mPixmap = QPixmap(":/images/goombas.png");
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timer->start(100);

    if (mDirection>0)
        setTransform(QTransform(-mDirection, 0, 0, 1, boundingRect().width(), 0));
}

void Enemy::nextFrame() {
    mCurrentFrame += 54;
    if (mCurrentFrame >= 862 ) {
        mCurrentFrame = 0;
    }

    if(this->pos().x() < mplateau.x() || this->pos().x() > mplateau.x() + mplateau.width()) {
        mDirection = -mDirection;
        setTransform(QTransform(-mDirection, 0, 0, 1, boundingRect().width(), 0));
    }
    setPos(this->pos().x() + (mDirection*7), this->pos().y());

    //Collision Detection
    QList<QGraphicsItem *> colliding_items = collidingItems();
    //If one of the colliding items is an Enemy, destroy the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){

            emit marioStatus(1);
            delete colliding_items[i];
//            qDebug()<<"mario dead";
            delete this;
            return;
        }
    }
}

QRectF Enemy::boundingRect() const {
    return QRectF(0,0,52,50);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0, 52, 50);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option)
}

int Enemy::type() const{
    return Type;
}


