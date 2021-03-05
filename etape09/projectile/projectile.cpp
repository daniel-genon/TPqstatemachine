#include "projectile.h"
#include <QtCore/QPropertyAnimation>
//#include <QtCore/QFinalState>
#include <QtCore/QSignalTransition>
#include <QMessageBox>
#include "deplacepjl.h"
#include "arretpjl.h"
Projectile::Projectile(QGraphicsItem *pcbl, Joueur *pstir)
{
    InitImage(QString(":/motif/projectile.png"));
    setZValue(4);
    InitPas(2);
    pcible  = pcbl;
    pjoueur = pstir;
    animationdelobjet = new QPropertyAnimation(this, "pos");
    animationdelobjet->setDuration(1000);
    connect(animationdelobjet,SIGNAL( valueChanged(QVariant)),this, SLOT(LeProjectileBouge(QVariant)));

    machine = new QStateMachine(this);
    ArretPjl *arret = new ArretPjl(this,machine);
    DeplacePjl *avance=new DeplacePjl(this,machine);

    QSignalTransition *etpan = new QSignalTransition(pjoueur, SIGNAL(OrdreDeTir()));
    arret->addTransition(etpan);
    etpan->setTargetState(avance);

    QSignalTransition *rearme = new QSignalTransition(animationdelobjet,SIGNAL(finished()));
    avance->addTransition(rearme);
    rearme->setTargetState(arret);

    QSignalTransition *dedans = new QSignalTransition(this, SIGNAL(Choc()));
    avance->addTransition(dedans);
    dedans->setTargetState(arret);

    machine->setInitialState(arret);
}
Projectile::~Projectile(){}
void Projectile::Initialiser()
{
    setPos(0,0);
    hide();
    BougeToi();
}
void Projectile::Tirer()
{
    pntdep = pjoueur->pos();
    pntfin=pntdep;
    switch(pjoueur->CodeDirection())
    {
    case Qt::Key_4 :{//gauche
             pntfin.setX(0);
            }break;
    case Qt::Key_6 :{
             pntfin.setX(pvue->scene()->width());
            }break;
    case Qt::Key_8 :{//haut
             pntfin.setY(0);
            }break;
    case Qt::Key_2 :{//bas
             pntfin.setY(pvue->scene()->height());
            }break;
    default : pntfin.setY(0);
    }
    setPos(pntdep);
    show();
    MajMouvement();
}
void Projectile::LeProjectileBouge(const QVariant &)
{
    if(TestCollision())
    {
        animationdelobjet->stop();
        emit Choc();
    }
}
void Projectile::InitPtrVue( Vue *vpvue )
{
    pvue=vpvue;
    if (pvue==0) { QMessageBox::information(NULL,"info","pas de scene");}
}
bool Projectile::TestCollision()
{
    QList<QGraphicsItem*> lstobjet = collidingItems(Qt::IntersectsItemBoundingRect);
    for(int i=0;i<lstobjet.count();i++)
    {
       if(pcible==lstobjet.at(i)) return true;
    }
    return false;
}
