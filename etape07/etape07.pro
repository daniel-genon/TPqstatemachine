#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Programmer avec QStateMachine"
# chapitre : Etape 07 : un objet libre + un objet contrôlé
# Daniel Génon OCT 2018 Revin
# version : 3 : 22/11/2021 adaptation pour QT 6.2
#-------------------------------------------------

QT += core gui
QT += widgets
QT += statemachine

TARGET = etape07
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
    joueur/arret.cpp \
    joueur/bougeadroite.cpp \
    joueur/bougeagauche.cpp \
    joueur/bougeenbas.cpp \
    joueur/bougeenhaut.cpp \
    joueur/joueur.cpp \
    joueur/transaccelere.cpp \
    joueur/transdemarre.cpp \
    joueur/transfrein.cpp \
    joueur/transinverse.cpp \
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
    joueur/arret.h \
    joueur/bougeadroite.h \
    joueur/bougeagauche.h \
    joueur/bougeenbas.h \
    joueur/bougeenhaut.h \
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
