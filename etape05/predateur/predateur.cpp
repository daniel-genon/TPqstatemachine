#include "predateur.h"
#include <QtCore/QPropertyAnimation>
#include <QFinalState>
#include <QSignalTransition>
#include "deplaceprd.h"
#include "arretprd.h"
#include "scene.h"
#include <QMessageBox>
Predateur::Predateur()
{
    InitImage(QString(":/motif/predateur.png"));
    setZValue(4);
    setFlags(QGraphicsItem::ItemIsFocusable);
    InitPas(50);
    animationdelobjet = new QPropertyAnimation( this, "pos" );
    animationdelobjet->setDuration(4000);
    machine = new QStateMachine(this);
    DeplacePrd *avance = new DeplacePrd( this, machine);
    ArretPrd   *arrete = new ArretPrd( this, machine );
    QSignalTransition *reprend = new QSignalTransition( animationdelobjet, SIGNAL(finished()) );
    avance->addTransition(reprend);
    reprend->setTargetState(arrete);
    arrete->addTransition( arrete, SIGNAL( RePositionner()), avance );
    machine->setInitialState(avance);
}
void Predateur::Initialiser()
{
    hide();
    pntfin=QPointF( (scene()->width() - size().width()), 0 );
    pntdepart=QPointF( 0, (scene()->height()) - size().height() );
    setPos(pntdepart);
    show();
}
void Predateur::InitPtrVue( Vue *vpvue )
{
    pvue=vpvue;
    if (pvue==0) { QMessageBox::information(NULL,"info", "pas de scene"); }
}
void Predateur::MajMouvement()
{
    animationdelobjet->stop();
    animationdelobjet->setStartValue(pntdepart);
    animationdelobjet->setEndValue(pntfin);
    animationdelobjet->start();
}
