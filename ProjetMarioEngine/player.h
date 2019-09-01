

#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>

class Player: public QGraphicsItem
{
public:
    Player(QGraphicsItem *parent = 0);
    ~Player();
   int direction() const;
   int standingDirection() const;
   void addStandingDirection(int standingDirection);
   void addDirection(int direction);
   void nextFrame();
   QRectF boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   bool isTouchingFoot(QGraphicsItem *item);
   bool isTouchingHead(QGraphicsItem *item);
   bool isTouchingPlatform(QGraphicsItem *item);

   void stand();
   void jump();
   void standShoot();
   void walk();
   void fall();
   bool isFalling();

private:
   enum State {
        Standing = 0,
        StandShoot,
        Walking,
        Jumping,
        Falling
   };

   int m_direction;
   int mCurrentFrame;
   int m_StandingDirection;
   State mState;
   QPixmap mPixmap;
   QPixmap mWalkPixmap;
   QPixmap mStandingPixmap;
   QPixmap mJumpPixmap;
   QPixmap standShootPixmap;

};

#endif // PLAYER_H


//#ifndef PLAYER_H
//#define PLAYER_H

//#include <QGraphicsRectItem>
//#include <QObject>

//class Player: public QObject, public QGraphicsRectItem
//{
//Q_OBJECT
//public:
//    Player();
//public:
//    void keyPressEvent(QKeyEvent * event);
//public:
//    void keyReleaseEvent(QKeyEvent * event);
//public slots:
//    void goPlayer();

//};

//#endif // PLAYER_H

