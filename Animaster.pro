#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T19:33:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Animaster
TEMPLATE = app


SOURCES += src/main.cpp\
        ui/MainWindow.cpp \
    src/Combatant.cpp \
    src/DiceBag.cpp

HEADERS  += ui/MainWindow.h \
    src/Combatant.h \
    src/DiceBag.h

FORMS    += ui/MainWindow.ui
