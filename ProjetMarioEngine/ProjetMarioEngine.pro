#-------------------------------------------------
#
# Project created by QtCreator 2019-06-27T21:18:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetMarioEngine
TEMPLATE = app


SOURCES += main.cpp \
    backgrounditem.cpp \
    brickplatform.cpp \
    enemy.cpp \
    flag.cpp \
    levelscene.cpp \
    mainview.cpp \
    mainwin.cpp \
    player.cpp \
    warptube.cpp \
    wingamedialog.cpp

HEADERS  += \
    backgrounditem.h \
    brickplatform.h \
    enemy.h \
    flag.h \
    levelscene.h \
    mainview.h \
    mainwin.h \
    player.h \
    warptube.h \
    wingamedialog.h

FORMS    += \
    wingamedialog.ui

RESOURCES += \
    resources.qrc
