
#include <QApplication>
#include <QLabel>

#include "mainwin.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWin mainWin;
    mainWin.setSize();

    mainWin.show();

    return a.exec();

}

//////////////////
//#include <QApplication>

//#include "player.h"
//#include "mainview.h"

//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <QTimer>

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);

//    //start timer to play
//    QTimer * timer = new QTimer();

//    // Create scene
//    QGraphicsScene * scene = new QGraphicsScene();

//    Player * player = new Player();

//    // add the item to the scene
//    scene->addItem(player);

//    //make rect focusable
//    player->setFlag(QGraphicsItem::ItemIsFocusable);
//    player->setFocus();

//    // add a view
//    MainView * view = new MainView(scene, player, timer);

//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    view->setStyleSheet("background-color:white;");

//    // show view
//    view->show();
//    view->setFixedSize(800, 600);
//    scene->setSceneRect(0,0,800,600);

//    player->setPos(view->width()/2, view->height() - player->rect().height());

//    // spown enemies
////    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
////    timer->start(2000);

//    return app.exec();
//}


