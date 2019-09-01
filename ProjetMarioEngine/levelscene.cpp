#include "levelscene.h"
//#include "player.h"
//#include "backgrounditem.h"
//#include "mainview.h"
#include "wingamedialog.h"
#include "flag.h"

#include <QKeyEvent>
//#include <QPropertyAnimation>
//#include <QGraphicsView>
//#include <QGraphicsPixmapItem>
//#include <QScrollBar>

LevelScene::LevelScene(MainView* v, QObject *parent)
    : QGraphicsScene(0,0,8000,720, parent)
    , scroll(0)
    , viewer(v)

    , m_jumpHeight(200)
    , m_fieldWidth(8000)//width of the virtual world
    , m_velocity(7)
    , m_groundLevel(0)
    , m_jumpAnimation(new QPropertyAnimation(this))
    , m_platform()

    , m_player()
    , m_sky(0)

{
    viewer->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    scroll = new QScrollBar;
    scroll = viewer->horizontalScrollBar();

    this->setFocus();
    this->setSceneRect(0,0,1280,720);

    viewer->sceneSet(this);

    initPlayField();

    m_timer.setInterval(20);
    connect(&m_timer, &QTimer::timeout, this, &LevelScene::movePlayer);

    mFallTimer.setInterval(20);
    connect(&mFallTimer, &QTimer::timeout, this, &LevelScene::movePlayer);

    m_jumpAnimation->setTargetObject(this);
    m_jumpAnimation->setPropertyName("jumpFactor");
    m_jumpAnimation->setStartValue(0);
    m_jumpAnimation->setKeyValueAt(0.5, 1);
    m_jumpAnimation->setEndValue(0);
    m_jumpAnimation->setDuration(800);
    m_jumpAnimation->setEasingCurve(QEasingCurve::OutInQuad);

    connect(this, &LevelScene::jumpFactorChanged, this, &LevelScene::jumpPlayer);
    connect(m_jumpAnimation, &QPropertyAnimation::stateChanged, this, &LevelScene::jumpStatusChanged);

    bigMario = true;
    littleMario = false;

    jumping = false;
    falling = false;

    m_player->addStandingDirection(1);

}

//initialisation
void LevelScene::initPlayField(){
    setSceneRect(0,0,8000,720);

    m_groundLevel = 660;

    //add sky
    m_sky = new BackgroundItem(QPixmap(":/images/sky.png"));
    m_sky->setPos(0,0);
    addItem(m_sky);

    m_ground = new BackgroundItem(QPixmap(":/images/ground"));
    addItem(m_ground);
    m_ground->setPos(0, m_groundLevel );

    m_Scene = new BackgroundItem(QPixmap(":/images/Scene"));
    m_Scene->setPos(0, m_groundLevel - m_Scene->boundingRect().height());
    addItem(m_Scene);

    m_wall = new BackgroundItem(QPixmap(":/images/wallf2.png"));
    m_wall->setPos(2900, m_groundLevel - m_wall->boundingRect().height());
    addItem(m_wall);

    //Add flag Pole
    m_flag = new BackgroundItem(QPixmap(":/images/flag"));
    m_flag->setPos(7234, m_groundLevel - m_flag->boundingRect().height());
    addItem(m_flag);

    //Add Flag Animation
    flagVictory = new Flag();
    flagVictory->setPos(7320, m_groundLevel - flagVictory->boundingRect().height()-185);
    addItem(flagVictory);

    //Add Castle
    m_castle = new BackgroundItem(QPixmap(":/images/castle"));
    m_castle->setPos(7637, m_groundLevel - m_castle->boundingRect().height());
    addItem(m_castle);




    //creat player
    m_player = new Player();
    m_player->setPos(50, m_groundLevel - m_player->boundingRect().height() );
    addItem(m_player);

}

void LevelScene::setMarioSize(int n){

}

qreal LevelScene::jumpFactor() const{

    return m_jumpFactor;
}

void LevelScene::setJumpFactor(const qreal &jumpFactor){

    if (m_jumpFactor == jumpFactor)
        return;

    m_jumpFactor = jumpFactor;
    emit jumpFactorChanged(m_jumpFactor);
}

//Timer event for animations
void LevelScene::timerEvent(QTimerEvent *){

}

void LevelScene::checkTimer(){
    if (0 == m_player->direction()){
        m_player->stand();
        m_timer.stop();
    }
    else if (!m_timer.isActive()){
        m_timer.start();
        m_player->walk();
    }
}

//Player key movement
void LevelScene::keyPressEvent(QKeyEvent *event){
    if (event->isAutoRepeat())
        return;
    switch (event->key()){
        case Qt::Key_Right:
            m_player->addDirection(1);
            m_player->addStandingDirection(1);
            checkTimer();
        break;
        case Qt::Key_Left:
            m_player->addDirection(-1);
            m_player->addStandingDirection(-1);
            checkTimer();
        break;
        case Qt::Key_Space:
        if (mFallTimer.isActive()){
            return;
        }else{
            if(QAbstractAnimation::Stopped == m_jumpAnimation->state()){
                m_jumpAnimation->start();
            }
        }
        break;
        default:
        break;
    }

}

void LevelScene::keyReleaseEvent(QKeyEvent *event){
    if (event->isAutoRepeat())
        return;

    switch (event->key()) {
        case Qt::Key_Right:
            m_player->addDirection(-1);
            m_player->addStandingDirection(1);
            checkTimer();
        break;
        case Qt::Key_Left:
            m_player->addDirection(1);
            m_player->addStandingDirection(-1);
            checkTimer();
        break;
        default:
        break;
    }
}

void LevelScene::movePlayer(){

    checkCollidingFlag();

    if(bigMario){
        if (m_player->isFalling()){
            return;
        }
        m_player->nextFrame();
        int direction = m_player->direction();
        if (0 == direction)
            return;

        if(!(m_platform && m_player->isTouchingPlatform(m_platform))&& m_jumpAnimation->state() == QAbstractAnimation::Stopped){
            if(m_platform){
                m_player->fall();
                mFallTimer.start();
            }
        }


        const int dx = direction * m_velocity;

        if (direction > 0){

            if(m_player->pos().x()==7956){
                return;
            }

            m_player->moveBy(dx, 0);
            int diff = m_player->pos().x() - scroll->value();

            if(diff > 800){

                if(scroll->value() > 6720){
//                    qDebug()<<"6720";
                    return;
                }

                scroll->setValue(dx + scroll->value());
                m_sky->setPos(dx + m_sky->pos().x(), 0);
                m_Scene->setPos(dx + m_Scene->pos().x(), m_Scene->y());
            }
        }

        if (direction < 0){

            if(m_player->pos().x()<0){
                return;
            }

            m_player->moveBy(dx, 0);
            int diff = m_player->pos().x() - scroll->value();

            if(diff < 600){

                if(m_sky->pos().x() == 0){
                    return;
                }

                scroll->setValue(dx + scroll->value());
                m_sky->setPos(dx + m_sky->pos().x(), 0);
                m_Scene->setPos(dx + m_Scene->pos().x(), m_Scene->y());
            }
        }

    }

}

void LevelScene::fallPlayer(){
//    checkCollidingFlag();

    m_player->setPos(m_player->pos().x(), m_player->pos().y() +30);
    QGraphicsItem* item = collidingPlatforms();
    if(item && handleCollisionWithPlatform()){
        mFallTimer.stop();
        m_player->walk();
    }
    else if(m_player->pos().y() + m_player->boundingRect().height() >= m_groundLevel){
        m_player->setPos(m_player->pos().x(), m_groundLevel - m_player->boundingRect().height());
        mFallTimer.stop();
        m_player->walk();
        m_platform = 0;
    }
}

//Player jump movement
void LevelScene::jumpPlayer(){

    checkCollidingFlag();


    if (QAbstractAnimation::Stopped == m_jumpAnimation->state()){
        m_player->stand();
        return;
    }


    QGraphicsItem* item = collidingPlatforms();
    if(item){
        if(m_player->isTouchingHead(item)){

            m_jumpAnimation->stop();

            if(m_platform){
                m_player->setPos(m_player->pos().x(), m_platform->pos().y() - m_player->boundingRect().height());
                return;
            }
            if(!m_platform){
                m_player->setPos(m_player->pos().x(), m_groundLevel - m_player->boundingRect().height());
                return;
            }
        }
        else{
            if(handleCollisionWithPlatform()){
                return;
            }
        }
    }

    if(mFallTimer.isActive()){
        return;
    }
    qreal y = (m_groundLevel - m_player->boundingRect().height()) - m_jumpAnimation->currentValue().toReal() * m_jumpHeight;
    if(m_platform){
        y = (m_platform->pos().y() - m_player->boundingRect().height()) - m_jumpAnimation->currentValue().toReal() * m_jumpHeight;
        if(!(m_platform && m_player->isTouchingPlatform(m_platform)) && m_jumpFactor < 0.1 ) {
            if((m_player->pos().x() < m_platform->pos().x()) || (m_player->pos().x() > m_platform->pos().x() + m_platform->boundingRect().width())){
                if(!m_platform){
                    m_platform = 0;
                }
                if(m_player->pos().y() < m_groundLevel){
                    m_player->fall();
                    mFallTimer.start();
                    return;
                }
            }
        }
    }
    m_player->setPos(m_player->pos().x(), y);
}

void LevelScene::jumpStatusChanged(QAbstractAnimation::State newState, QAbstractAnimation::State oldState){
    if(newState == QAbstractAnimation::Stopped && oldState == QAbstractAnimation::Running){
        //handleCollisionWithPlatform();
    }
}

QGraphicsItem* LevelScene::collidingPlatforms(){
    //todo return platform without colision
    QList<QGraphicsItem*> items =  collidingItems(m_player);
    foreach(QGraphicsItem *item, items){
        //    if(BrickPlatform *brickplatform = qgraphicsitem_cast<BrickPlatform *>(item)){
        //        return brickplatform;
        //    }
    }
    return 0;
}

void LevelScene::checkCollidingFlag(){
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {
        Flag* f = qgraphicsitem_cast<Flag*>(item);
        if(f){
            removeItem(f);
//            addItem(courseclear);
            winGameDialog = new WinGameDialog();
            winGameDialog->setFixedSize(557,355);
            winGameDialog->setWindowFlags(((winGameDialog ->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint));
            winGameDialog->exec();
        }



    }
}

bool LevelScene::handleCollisionWithPlatform(){
    QGraphicsItem* platform =  collidingPlatforms();
    if(platform) {
        QPointF platformPos = platform->pos();
        if(m_player->isTouchingFoot(platform)){
            m_player->setPos(m_player->pos().x(), platformPos.y() - m_player->boundingRect().height());
            m_platform = platform;
            m_jumpAnimation->stop();
            return true;
        }
    }
    else{
        m_platform = 0;
    }
    return false;
}
