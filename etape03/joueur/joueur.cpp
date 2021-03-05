#include "joueur.h"
#include <QtCore/QPropertyAnimation>
#include <QtCore/QFinalState>
#include "bougeadroite.h"
#include "bougeagauche.h"
#include "arret.h"
#include "transdemarre.h"
#include "transaccelere.h"
#include "transfrein.h"
#include "transinverse.h"
#include "../etape01/scene.h"
#include <QMessageBox>
Joueur::Joueur()
{
    InitImage(QString(":/motif/joueur.png"));
    setZValue(4);
    setFlags(QGraphicsItem::ItemIsFocusable);
    vitesse         =  0;
    limitevitesse   = 10;
    acceleration    =  7;
    coefresiste     = 80;
    animationdelobjet = new QPropertyAnimation(this, "pos");
    machine = new QStateMachine(this);
    QState *conteneur = new QState(machine);
    Arret *arret = new Arret(this, conteneur);
    conteneur->setInitialState(arret);
    machine->setInitialState(conteneur);

    QKeyEventTransition *stopGD = new QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_5);
    conteneur->addTransition(stopGD);
    stopGD->setTargetState(arret);
    conteneur->addTransition(animationdelobjet, SIGNAL(finished()), arret);

    BougeADroite *bougeadroite = new BougeADroite(this, conteneur);
    BougeAGauche *bougeagauche = new BougeAGauche(this, conteneur);

    TransDemarre *depgah = new TransDemarre(this, QEvent::KeyPress, Qt::Key_4);
    arret->addTransition(depgah);
    depgah->setTargetState(bougeagauche);
    TransDemarre *depdrt = new TransDemarre(this, QEvent::KeyPress, Qt::Key_6);
    depdrt->setTargetState(bougeadroite);
    arret->addTransition(depdrt);

    TransAccelere *accelG = new TransAccelere(this, QEvent::KeyPress, Qt::Key_4);
    bougeagauche->addTransition(accelG);
    accelG->setTargetState(bougeagauche);
    TransInverse *GversD = new TransInverse( this,QEvent::KeyPress, Qt::Key_6);
    GversD->setTargetState(bougeadroite);
    bougeagauche->addTransition(GversD);
    TransFrein *freinG = new TransFrein(this, QEvent::KeyPress, Qt::Key_6);
    freinG->setTargetState(bougeagauche);
    bougeagauche->addTransition(freinG);

    TransAccelere *accelD = new TransAccelere(this, QEvent::KeyPress, Qt::Key_6);
    accelD->setTargetState(bougeadroite);
    bougeadroite->addTransition(accelD);
    TransInverse *DversG = new TransInverse( this,QEvent::KeyPress, Qt::Key_4);
    DversG->setTargetState(bougeagauche);
    bougeadroite->addTransition(DversG);
    TransFrein *freinD = new TransFrein(this, QEvent::KeyPress, Qt::Key_4);
    bougeadroite->addTransition(freinD);
    freinD->setTargetState(bougeadroite);
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
    if (pvue==0)
    {
        QMessageBox::information(NULL, "info","pas de scene");
    }
}
void Joueur::InverserDeplacement()
{
    if(VaADroite())
        DirectionGauche();
    else
        DirectionDroite();
}
void Joueur::AnnulerVitesse(){ vitesse=0;}
void Joueur::AugmenterVitesse()
{    if(vitesse<limitevitesse){ vitesse++; }}
void Joueur::DiminuerVitesse()
{
    if(vitesse>0)
    {
        vitesse--;
        if(vitesse==0) FixerObjet();
    }
}
void Joueur::VitesseInitiale(){ vitesse=1;}
quint8 Joueur::Vitesse() const { return vitesse;}
bool Joueur::VitesseNulle() const {return vitesse==0;}
bool Joueur::VitessePasNulle() const { return vitesse!=0;}
bool Joueur::VitesseMinimale() const { return vitesse==1;}
void Joueur::FixerObjet()
{
    AnnulerVitesse();
    ObjetMobile::FixerObjet();
}
void Joueur::MajMouvement()
{
    animationdelobjet->stop();
    if ( Immobile()||VitesseNulle() ) return;
    int vitesseaccel = Vitesse()*acceleration;
    if (vitesseaccel==0) return;
    int     dureedepl = 0;
    bool    bougeok=true;
    QPointF npos = pos();
    switch(CodeDirection())
    {
    case Qt::Key_4 :{//gauche
        npos.setX(0);
        dureedepl = x() * coefresiste/vitesseaccel;
            }break;
    case Qt::Key_6 :{//droite
        npos.setX(scene()->width() - size().width());
        dureedepl = (scene()->width() - size().width()-x()) * coefresiste/vitesseaccel;
            }break;
    default : bougeok=false;
    }
    if (bougeok)
    {
        animationdelobjet->setEndValue(npos);
        animationdelobjet->setDuration(dureedepl);
        animationdelobjet->start();
    }
}

