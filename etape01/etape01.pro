#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Programmer avec QStateMachine"
# chapitre : Etape 01 : déplacement dans une seule direction
# Daniel Génon AOUT 2018 Revin
# version : 1
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = etape01
TEMPLATE = app
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    ../main.cpp \
    ../objetimage.cpp \
    ../fenetre.cpp \
    ../sequence.cpp \
    ../vue.cpp \
    ../zoneanime.cpp \
    ../parametre.cpp \
    joueur/joueur.cpp \
    joueur/bougeadroite.cpp \
    joueur/transtchbouge.cpp \
    joueur/arret.cpp \
    objetmobile.cpp \
    scene.cpp

HEADERS  += \
    ../objetimage.h \
    ../fenetre.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    ../parametre.h \
    joueur/joueur.h \
    joueur/bougeadroite.h \
    joueur/transtchbouge.h \
    joueur/arret.h \
    objetmobile.h \
    scene.h

RESOURCES += \
    ..\ressources.qrc

FORMS += \
    ..\parametre.ui

