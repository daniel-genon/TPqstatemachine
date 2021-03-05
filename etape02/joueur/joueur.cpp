#include "joueur.h"
#include <QtCore/QPropertyAnimation>
#include <QtCore/QFinalState>
#include "bougeadroite.h"
#include "bougeagauche.h"
#include "arret.h"
#include "transdemarre.h"
#include "transinverse.h"
#include "../etape01/scene.h"
#include <QMessageBox>
Joueur::Joueur()
{
    InitImage(QString(":/motif/joueur.png"));
    setZValue(4);
    setFlags(QGraphicsItem::ItemIsFocusable);
    duree = 80;
    vitesse=0;
    animationdelobjet = new QPropertyAnimation(this,"pos");
    machine = new QStateMachine(this);
    Arret *arret = new Arret(this, machine);
    machine->setInitialState(arret);
    BougeADroite *bougeadroite   = new BougeADroite(this, machine);
    BougeAGauche *bougeagauche   = new BougeAGauche(this, machine);

    QKeyEventTransition *stopG = new QKeyEventTransition(this, QEvent::KeyPress,Qt::Key_5);
      bougeagauche->addTransition(stopG);
      stopG->setTargetState(arret);
    QKeyEventTransition *stopD = new QKeyEventTransition(this, QEvent::KeyPress,Qt::Key_5);
      bougeadroite->addTransition(stopD);
      stopD->setTargetState(arret);

    TransDemarre *SversG = new TransDemarre(this, QEvent::KeyPress, Qt::Key_4);
    SversG->setTargetState(bougeagauche);
    arret->addTransition(SversG);
    TransDemarre *SversD = new TransDemarre(this, QEvent::KeyPress, Qt::Key_6);
    SversD->setTargetState(bougeadroite);
    arret->addTransition(SversD);

    TransInverse *DversG = new TransInverse(this, QEvent::KeyPress,Qt::Key_4);
    DversG->setTargetState(bougeagauche);
    bougeadroite->addTransition(DversG);
    TransInverse *GversD = new TransInverse(this, QEvent::KeyPress,Qt::Key_6);
    GversD->setTargetState(bougeadroite);
    bougeagauche->addTransition(GversD);
}
void Joueur::ReInitialiser()
{
    vitesse = scene()->width()/duree;
    FixerObjet();
    setPos((pvue->scene()->width()-size().width())/2,(pvue->scene()->height()-size().height())/2);
    show();
    BougeToi();
}
void Joueur::InitPtrVue(Vue *vpvue )
{
    pvue=vpvue;
    if (pvue==0){QMessageBox::information(NULL,"info","pas de scene");}
}
void Joueur::InverserDeplacement()
{
    switch(CodeDirection())
    {
        case Qt::Key_4 :{DirectionDroite();}break;//gauche
        case Qt::Key_6 :{DirectionGauche();}break;//droite
    }
}
void Joueur::MajMouvement()
{
    animationdelobjet->stop();
    int trajet;
    bool    bougeok=true;
    QPointF npos = pos();
    switch(CodeDirection())
    {
    case Qt::Key_4 :{trajet=npos.x();npos.setX(0);}break;//gauche
    case Qt::Key_6 :{trajet=scene()->width()-npos.x(); npos.setX(scene()->width()-size().width());}break;//droite
    default : bougeok=false;
    }
    if (bougeok)
    {
        animationdelobjet->setEndValue(npos);
        animationdelobjet->setDuration(vitesse*trajet);
        animationdelobjet->start();
    }
}

