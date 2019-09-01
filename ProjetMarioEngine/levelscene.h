#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QDebug>

#include "player.h"
#include "mainwin.h"
#include "backgrounditem.h"

class MainView;
class QGraphicsPixmapItem;
class QPropertyAnimation;
class Player;
class QScrollBar;

class LevelScene : public QGraphicsScene
{
    Q_OBJECT
    Q_PROPERTY(qreal jumpFactor READ jumpFactor WRITE setJumpFactor NOTIFY jumpFactorChanged)
public:
    explicit LevelScene(MainView *v, QObject *parent = 0);
    void timerEvent(QTimerEvent *);
    qreal jumpFactor() const;
    void setJumpFactor(const qreal &jumpFactor);
protected:
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

private slots:
    void movePlayer();
    void jumpPlayer();
    void fallPlayer();
    void checkTimer();
    void setMarioSize(int);

    bool handleCollisionWithPlatform();
    QGraphicsItem* collidingPlatforms();
    void jumpStatusChanged(QAbstractAnimation::State newState, QAbstractAnimation::State oldState);

signals:
    void jumpFactorChanged(qreal);

private:
    void initPlayField();


    QScrollBar *scroll;
    MainView *viewer;

    qreal m_jumpFactor;
    int m_jumpHeight;
    int m_fieldWidth;

    int m_velocity;
    qreal m_groundLevel;
    QTimer m_timer;
    QTimer mFallTimer;
    QPropertyAnimation *m_jumpAnimation;
    QGraphicsItem *m_platform;

    Player* m_player;
//    SmallPlayer* m_smallPlayer;

    BackgroundItem *m_sky;
    BackgroundItem *m_Scene;
    BackgroundItem *m_ground;
    BackgroundItem *m_wall;

    bool bigMario;
    bool littleMario;
    bool falling;
    bool jumping;

};

#endif // LEVELSCENE_H
