#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QScrollBar>

#include "mainview.h"
#include "levelscene.h"

class LevelScene;
class MainView;
class MyScene;

class MainWin: public QMainWindow
{
    Q_OBJECT
public:
    MainWin();
    void setSize();
private:
    void closeEvent(QCloseEvent *event);
private:
    void createScene();
    MainView *view;
    LevelScene *levelScene;
    QScrollBar *scroll;
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
};

#endif // MAINWIN_H
