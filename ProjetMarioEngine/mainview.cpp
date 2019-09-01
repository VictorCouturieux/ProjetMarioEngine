#include "mainview.h"

MainView::MainView()
{

    this->setFixedSize(QSize(1280, 720));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void MainView::sceneSet(QGraphicsScene *scene) {

    setScene(scene);
    emit sceneChanged();
}
