#include "joueur.h"
#include <QtCore/QPropertyAnimation>
#include <QFinalState>
#include <QMessageBox>
#include "../scene.h"
#include "bougeadroite.h"
#include "bougeagauche.h"
#include "bougeenhaut.h"
#include "bougeenbas.h"
#include "arret.h"
#include "transdemarre.h"
#include "transfrein.h"
#include "transaccelere.h"
#include "transinverse.h"
#include "transetpan.h"
Joueur::Joueur()
{
    InitImage(QString(":/motif/joueur.png"));
    setZValue(4);
    setFlags(QGraphicsItem::ItemIsFocusable);
    vitesse         =   0;
    limitevitesse   =  20;
    acceleration    =   2;
    coefresiste     = 100;
    animationdelobjet = new QPropertyAnimation(this, "pos");
    machine = new QStateMachine(this);
    QState *conteneur = new QState(machine);
    Arret *arret = new Arret(this, conteneur);
    conteneur->setInitialState(arret);
    machine->setInitialState(conteneur);
    QKeyEventTransition *arrete = new QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_5);
    conteneur->addTransition(arrete);
    arrete->setTargetState(arret);
    conteneur->addTransition(animationdelobjet, SIGNAL(finished()), arret);

    BougeADroite *bougeadroite   = new BougeADroite( this, conteneur);
    BougeAGauche *bougeagauche   = new BougeAGauche( this, conteneur);
    BougeEnHaut  *bougeenhaut    = new BougeEnHaut(  this, conteneur);
    BougeEnBas   *bougeenbas     = new BougeEnBas(   this, conteneur);

    TransDemarre *deplaceD = new TransDemarre(this, QEvent::KeyPress, Qt::Key_6);
    deplaceD->setTargetState(bougeadroite);
    arret->addTransition(deplaceD);
    TransDemarre *deplaceG = new TransDemarre(this, QEvent::KeyPress, Qt::Key_4);
    deplaceG->setTargetState(bougeagauche);
    arret->addTransition(deplaceG);
    TransDemarre *deplaceH = new TransDemarre(this, QEvent::KeyPress, Qt::Key_8);
    deplaceH->setTargetState(bougeenhaut);
    arret->addTransition(deplaceH);
    TransDemarre *deplaceB = new TransDemarre(this, QEvent::KeyPress, Qt::Key_2);
    deplaceB->setTargetState(bougeenbas);
    arret->addTransition(deplaceB);

//transitions sans cible
    TransAccelere *accelD = new TransAccelere(this, QEvent::KeyPress, Qt::Key_6);
    bougeadroite->addTransition(accelD);
    TransAccelere *accelG = new TransAccelere(this, QEvent::KeyPress, Qt::Key_4);
    bougeagauche->addTransition(accelG);
    TransAccelere *accelH = new TransAccelere(this, QEvent::KeyPress, Qt::Key_8);
    bougeenhaut->addTransition(accelH);
    TransAccelere *accelB = new TransAccelere(this, QEvent::KeyPress, Qt::Key_2);
    bougeenbas->addTransition(accelB);

//transitions partagées
    TransInverse *versG = new TransInverse(this, QEvent::KeyPress, Qt::Key_4);
    conteneur->addTransition(versG);
    versG->setTargetState(bougeagauche);
    TransInverse *versD = new TransInverse(this, QEvent::KeyPress, Qt::Key_6);
    conteneur->addTransition(versD);
    versD->setTargetState(bougeadroite);
    TransInverse *versH = new TransInverse(this, QEvent::KeyPress, Qt::Key_8);
    conteneur->addTransition(versH);
    versH->setTargetState(bougeenhaut);
    TransInverse *versB = new TransInverse(this, QEvent::KeyPress, Qt::Key_2);
    conteneur->addTransition(versB);
    versB->setTargetState(bougeenbas);

//transitions sans cible et partagées
    TransFrein *freinG = new TransFrein(this, QEvent::KeyPress, Qt::Key_4);
    conteneur->addTransition(freinG);
    TransFrein *freinD = new TransFrein(this, QEvent::KeyPress, Qt::Key_6);
    conteneur->addTransition(freinD);
    TransFrein *freinH = new TransFrein(this, QEvent::KeyPress, Qt::Key_8);
    conteneur->addTransition(freinH);
    TransFrein *freinB = new TransFrein(this, QEvent::KeyPress, Qt::Key_2);
    conteneur->addTransition(freinB);

    TransEtPan *pan = new TransEtPan(this, QEvent::KeyPress, Qt::Key_Space);
    conteneur->addTransition(pan);

}
void Joueur::ReInitialiser()
{
    AnnulerVitesse();
    FixerObjet();
    setPos((pvue->scene()->width() - size().width())/2, (pvue->scene()->height() - size().height())/2);
    show();
    BougeToi();
}
void Joueur::InitPtrVue(Vue *vpvue )
{
    pvue=vpvue;
    if (pvue==0) { QMessageBox::information(NULL,"info","pas de scene");}
}
void Joueur::Tirer(){ emit OrdreDeTir();}
void Joueur::AnnulerVitesse(){ vitesse=0;}
void Joueur::AugmenterVitesse(){ if(vitesse<limitevitesse){ vitesse++; } }
void Joueur::DiminuerVitesse()
{
    if(vitesse>0)
    {
        vitesse--;
        if(vitesse==0) FixerObjet();
    }
}
void Joueur::VitesseInitiale()       { vitesse=1;}
quint8 Joueur::Vitesse() const       { return vitesse;}
bool Joueur::VitesseNulle() const    { return vitesse==0;}
bool Joueur::VitessePasNulle() const { return vitesse!=0;}
bool Joueur::VitesseMinimale() const { return vitesse==1;}
bool Joueur::VitesseMaximale() const { return vitesse==limitevitesse;}

void Joueur::MajMouvement()
{
    animationdelobjet->stop();
    if ( Immobile()||VitesseNulle() ) return;
    bool    bougeok=true;
    int     vitesseaccel = Vitesse()*acceleration;
    if (vitesseaccel==0) return;
    QPointF npos(pos());
    switch(CodeDirection())
    {
    case Qt::Key_4 :{//gauche
            npos.setX(0);
            vitesseaccel = x() * coefresiste/vitesseaccel;
            }break;
    case Qt::Key_6 :{//droite
            npos.setX(scene()->width() - size().width());
            vitesseaccel = (scene()->width() - size().width()-x()) * coefresiste/vitesseaccel;
            }break;
    case Qt::Key_8 :{//haut
            npos.setY(0);
            vitesseaccel = y() * coefresiste/vitesseaccel;
            }break;
    case Qt::Key_2 :{//bas
            npos.setY(scene()->height() - size().height());
            vitesseaccel = (scene()->height() - size().height()-y()) * coefresiste/vitesseaccel;
            }break;
    default : bougeok=false;
    }
    if (bougeok)
    {
        animationdelobjet->setEndValue(npos);
        animationdelobjet->setDuration(vitesseaccel);
        animationdelobjet->start();
    }
}

