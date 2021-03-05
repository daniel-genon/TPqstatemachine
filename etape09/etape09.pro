#-------------------------------------------------
# Project created by QtCreator
# Support TP du livre "Programmer avec QStateMachine"
# chapitre : Etape 09 : un objet produit un objet et le démarre
# Daniel Génon NOV 2018 Revin
# version : 5
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = etape09
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
    joueur/bougeenbas.cpp \
    joueur/bougeenhaut.cpp \
    joueur/joueur.cpp \
    joueur/transaccelere.cpp \
    joueur/transdemarre.cpp \
    joueur/transfrein.cpp \
    joueur/transinverse.cpp \
    joueur/transetpan.cpp \
    predateur/arretprd.cpp \
    predateur/deplaceprd.cpp \
    predateur/trcontact.cpp \
    predateur/predateur.cpp \
    projectile/arretpjl.cpp \
    projectile/deplacepjl.cpp \
    projectile/projectile.cpp \
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
    joueur/bougeenbas.h \
    joueur/bougeenhaut.h \
    joueur/joueur.h \
    joueur/transaccelere.h \
    joueur/transdemarre.h \
    joueur/transfrein.h \
    joueur/transinverse.h \
    joueur/transetpan.h \
    predateur/arretprd.h \
    predateur/deplaceprd.h \
    predateur/predateur.h \
    predateur/trcontact.h \
    projectile/arretpjl.h \
    projectile/deplacepjl.h \
    projectile/projectile.h \
    objetmobile.h \
    scene.h


RESOURCES += \
    ../ressources.qrc

FORMS += \
    ../parametre.ui
