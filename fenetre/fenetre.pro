#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Programmer avec QStateMachine"
# chapitre : Fenêtre de l'application
# Daniel Génon AOUT 2018 Revin
# version : 2 - 19/11/2021 adaptation pour QT 6.2
#-------------------------------------------------

QT += core gui
QT += widgets
QT += statemachine

TARGET = fenetre
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
    scene.cpp

HEADERS += \
    ../fenetre.h \
    ../objetimage.h \
    ../sequence.h \
    ../vue.h \
    ../zoneanime.h \
    ../parametre.h \
    scene.h

RESOURCES += \
    ../ressources.qrc

FORMS += \
    ../parametre.ui
