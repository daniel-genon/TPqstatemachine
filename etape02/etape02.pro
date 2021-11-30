#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Programmer avec QStateMachine"
# chapitre : Etape 02 : déplacement dans deux directions contraires
# Daniel Génon AOUT 2018 Revin
# version : 3 - 19/11/2021 adaptation pour QT 6.2
#-------------------------------------------------

QT += core gui
QT += statemachine
QT += widgets

TARGET = etape02
TEMPLATE = app
CONFIG += c++11

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
    joueur/bougeagauche.cpp \
    joueur/transinverse.cpp \
    joueur/transdemarre.cpp \
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
    joueur/bougeagauche.h \
    joueur/transinverse.h \
    joueur/transdemarre.h \
    joueur/arret.h \
    objetmobile.h \
    scene.h

RESOURCES += \
    ../ressources.qrc

FORMS += \
    ../parametre.ui
