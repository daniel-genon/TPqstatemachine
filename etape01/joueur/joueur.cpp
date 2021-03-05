#include "joueur.h"
#include <QtCore/QPropertyAnimation>
#include <QtCore/QFinalState>
#include "bougeadroite.h"
#include "arret.h"
#include "transtchbouge.h"
#include "scene.h"
#include <QMessageBox>

Joueur::Joueur()
{
    InitImage(QString(":/motif/joueur.png"));
    setZValue(4);
    InitPas(200);
    setFlags(QGraphicsItem::ItemIsFocusable);
    animationdelobjet = new QPropertyAnimation(this,"pos");
    animationdelobjet->setDuration(500);
    machine = new QStateMachine(this);

    BougeADroite *bougeadroite=new BougeADroite( this, machine);
    Arret *arret = new Arret(this, machine);
    TransTchBouge *avance=new TransTchBouge( this, QEvent::KeyPress,Qt::Key_6);
    avance->setTargetState(bougeadroite);
    arret->addTransition(avance);
    TransTchBouge *arrete=new TransTchBouge( this ,QEvent::KeyPress,Qt::Key_5);
    arrete->setTargetState(arret);
    bougeadroite->addTransition(arrete);
    bougeadroite->addTransition(animationdelobjet,SIGNAL(finished()),arret);

    machine->setInitialState(arret);
}
void Joueur::ReInitialiser()
{
    FixerObjet();
    setPos(0, (pvue->scene()->height()-size().height())/2);
    show();
    BougeToi();
}
void Joueur::InitPtrVue( Vue *vpvue )
{
    pvue=vpvue;
    if (pvue==0){ QMessageBox::information(NULL,"info","pas de scene"); }
}
void Joueur::MajMouvement()
{
    animationdelobjet->stop();
    if ( Mobile() )
    {
        if(VaADroite())
        {
            qreal tmpr = (scene()->width()-size().width());
            if( x()<tmpr )
            {
                npos = pos();
                npos.setX(x()+ValeurPas());
                if(npos.rx()>tmpr){npos.setX(tmpr);}
                animationdelobjet->setEndValue(npos);
                animationdelobjet->start();
            }
        }
    }
}
