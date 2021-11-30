#include "projectile.h"
#include <QtCore/QPropertyAnimation>
#include <QSignalTransition>
#include <QMessageBox>
#include "deplacepjl.h"
#include "arretpjl.h"
#include "aubut.h"
Projectile::Projectile(Predateur *pcbl, Joueur *pstir)
{
    InitImage(QString(":/motif/projectile.png"));
    setZValue(4);
    InitPas(2);
    hide();
    pcible  = pcbl;
    pjoueur = pstir;
    pvue    = pjoueur->pVue();
    animationdelobjet = new QPropertyAnimation(this,"pos");
    animationdelobjet->setDuration(1000);
    connect(animationdelobjet,SIGNAL(valueChanged(QVariant)), this, SLOT(LeProjectileBouge(QVariant)));

    machine = new QStateMachine(this);
    ArretPjl   *arret = new ArretPjl(this,machine);
    DeplacePjl *avance=new DeplacePjl(this,machine);
    AuBut      *etpaf = new AuBut(this,machine);

    QSignalTransition *dedans=new QSignalTransition(this, SIGNAL(Contact()));
    avance->addTransition(dedans);
    dedans->setTargetState(etpaf);

    QSignalTransition *manquer=new QSignalTransition(animationdelobjet, SIGNAL(finished()));
    avance->addTransition(manquer);
    manquer->setTargetState(arret);

    machine->setInitialState(avance);
}
Projectile::~Projectile(){}
void Projectile::Tirer()
{
    pntdep = pjoueur->pos();
    pntfin=pntdep;
    switch(pjoueur->CodeDirection())
    {
    case Qt::Key_4 :{ pntfin.setX(0);}break;//gauche
    case Qt::Key_6 :{ pntfin.setX(pvue->scene()->width());}break;//droite
    case Qt::Key_8 :{ pntfin.setY(0);}break;//haut
    case Qt::Key_2 :{ pntfin.setY(pvue->scene()->height());}break;//bas
    default : pntfin.setY(0);
    }
    setPos(pntdep);
    show();
    BougeToi();
}
void Projectile::LeProjectileBouge(const QVariant &)
{
    if(TestCollision()){ emit Contact(); }
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
void Projectile::Detruire()
{
    hide();
    Stop();
    pcible->Initialiser(QPointF(0,0));
    emit Boum();
}
void Projectile::Foirer()
{
    hide();
    Stop();
    emit Limite();
}
