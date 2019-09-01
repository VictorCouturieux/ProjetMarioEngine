#include "mainwin.h"
#include <iostream>

MainWin::MainWin()
{
    createScene();
    setCentralWidget(view);
    setWindowTitle("Super Mario");
}

void MainWin::closeEvent(QCloseEvent *){
    qApp->quit();
}

void MainWin::createScene(){
    view = new MainView;
    view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

    levelScene = new LevelScene(view);

}

void MainWin::setSize(){

    this->setFixedSize(1280,740);
    int x = ((screenGeometry.width() - this->width()) / 2);
    int y = ((screenGeometry.height() - this->height()) / 2);
    this->move(x, y);
}
