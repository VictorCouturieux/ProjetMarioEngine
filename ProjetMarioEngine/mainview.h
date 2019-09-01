#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "mainwin.h"
#include <QWidget>

class MainView: public QGraphicsView
{
    Q_OBJECT
signals:
    void sceneChanged();

public:
    MainView();
    void sceneSet(QGraphicsScene *);
};

#endif // MAINVIEW_H
