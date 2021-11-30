#include "predateur.h"
#include <QtCore/QPropertyAnimation>
#include <QFinalState>
#include <QSignalTransition>
#include <QMessageBox>
#include "deplaceprd.h"
#include "arretprd.h"
#include "trcontact.h"
#include "../scene.h"
Predateur::Predateur(Joueur *valptr)
{
    InitImage(QString(":/motif/predateur.png"));
    setZValue(4);
    InitPas(2);
    pjoueur = valptr;
    animationdelobjet = new QPropertyAnimation(this, "pos");
    animationdelobjet->setDuration(4);
    machine = new QStateMachine(this);
    DeplacePrd *avance =new DeplacePrd(this, machine);
    ArretPrd   *arrete =new ArretPrd  (this, machine);
    TrContact *dedans=new TrContact(this, avance);
    avance->addTransition(dedans);
    dedans->setTargetState(arrete);
    QSignalTransition *reprend=new QSignalTransition( animationdelobjet,SIGNAL(finished()));
    avance->addTransition(reprend);
    reprend->setTargetState(arrete);
    arrete->addTransition(arrete,SIGNAL( RePositionner()),avance);
    machine->setInitialState(avance);
}
void Predateur::Initialiser(const QPointF& pdep)
{
    pntdep=pdep;
    pntfin=pdep;
    pntfin.setX(pntdep.rx()+1);
    hide();
    setPos(pntdep);
    show();
    BougeToi();
}
void Predateur::InitPtrVue( Vue *vpvue )
{
    pvue=vpvue;
    if (pvue==0){ QMessageBox::information(NULL,"info","pas de scene");}
}
void Predateur::MajMouvement()
{
        animationdelobjet->setEndValue(pntfin);
        animationdelobjet->start();
}
void Predateur::PositionCible()
{    PointCible(pjoueur->pos());}
bool Predateur::TestCollision()
{
    QList<QGraphicsItem*> lstobjet = collidingItems(Qt::IntersectsItemBoundingRect);
    for(int i=0;i<lstobjet.count();i++)
    {
       if((ObjetImage*)pjoueur==(ObjetImage*)lstobjet.at(i)) return true;
    }
    return false;
}
