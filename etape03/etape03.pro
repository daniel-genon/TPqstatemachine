#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Programmer avec QStateMachine"
# chapitre : Etape 03 : déplacement dans deux directions accélèration et freinage.
# Daniel Génon AOUT 2018 Revin
# version : 2
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = etape03
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
    joueur/arret.cpp \
    joueur/bougeadroite.cpp \
    joueur/bougeagauche.cpp \
    joueur/joueur.cpp \
    joueur/transaccelere.cpp \
    joueur/transdemarre.cpp \
    joueur/transfrein.cpp \
    joueur/transinverse.cpp \
    objetmobile.cpp \
    scene.cpp

HEADERS += \
    ../objetimage.h \
    ../fenetre.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    ../parametre.h \
    joueur/arret.h \
    joueur/bougeadroite.h \
    joueur/bougeagauche.h \
    joueur/joueur.h \
    joueur/transaccelere.h \
    joueur/transdemarre.h \
    joueur/transfrein.h \
    joueur/transinverse.h \
    objetmobile.h \
    scene.h

RESOURCES += \
    ../ressources.qrc

FORMS += \
    ../parametre.ui
