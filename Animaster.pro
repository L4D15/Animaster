#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T19:33:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Animaster
TEMPLATE = app


SOURCES += src/main.cpp \
        ui/MainWindow.cpp \
        ui/CombatCard.cpp \

HEADERS  += ui/MainWindow.h \
            ui/CombatCard.h \

FORMS    += ui/MainWindow.ui \
            ui/CombatCard.ui \
    CombatCard.ui

RESOURCES += \
    ui/resources.qrc
