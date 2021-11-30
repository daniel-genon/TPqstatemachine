#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Programmer avec QStateMachine"
# chapitre : Etape 06 : série d'objets libres
# Daniel Génon SEPT 2018 Revin
# version : 2 : 22/11/2021 adaptation pour QT 6.2
#-------------------------------------------------

QT += core gui
QT += widgets
QT += statemachine

TARGET = etape06
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
    predateur/arretprd.cpp \
    predateur/deplaceprd.cpp \
    predateur/predateur.cpp \
    objetmobile.cpp \
    scene.cpp

HEADERS += \
    ../objetimage.h \
    ../fenetre.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    ../parametre.h \
    predateur/arretprd.h \
    predateur/deplaceprd.h \
    predateur/predateur.h \
    objetmobile.h \
    scene.h

RESOURCES += \
    ../ressources.qrc

FORMS += \
    ../parametre.ui
