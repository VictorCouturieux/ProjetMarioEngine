#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>

bool goLeft = false;
bool goRight = false;


Player::Player()
{
    setRect(0,0,100,100);

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(goPlayer()));

    timer->start(50);

}

void Player::keyPressEvent(QKeyEvent *event){
    //    QGraphicsView::keyPressEvent(event);
    //    QGraphicsItem::keyPressEvent(event);
    //    qDebug() << "Myrect knows that you pressed a key";
    //    std::cout << "Myrect knows that you pressed a key" << std::endl;

    if (event->key() == Qt::Key_Left){
        goLeft = pos().x() > 0;
    }
    if (event->key() == Qt::Key_Right){
        goRight = pos().x() + 100 < 800;
    }

    //    if (event->key() == Qt::Key_Up){
    //        _player->setPos(_player->x(),_player->y()-10);
    //    }
    //    if (event->key() == Qt::Key_Down){
    //        _player->setPos(_player->x(),_player->y()+10);
    //    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        goLeft = pos().x() < 0;
    }
    if(event->key() == Qt::Key_Right){
        goRight = pos().x() + 100 > 800;
    }
}

void Player::goPlayer() {
    if (goLeft){
        setPos(x()-20, y());
    }
    if (goRight){
        setPos(x()+20, y());
    }
}

