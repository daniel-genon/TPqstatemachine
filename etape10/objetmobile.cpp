#include "objetmobile.h"
#include <QtMath>
#include <QMessageBox>
ObjetMobile::ObjetMobile()
{
    pas=10;
    direction = 0;
    animationdelobjet = 0;
    machine=0;
}
ObjetMobile::~ObjetMobile()
{   if(machine){ machine->stop(); delete machine; }}
void ObjetMobile::BougeToi()
{    if(!machine->isRunning()) { machine->start();}}
void ObjetMobile::Stop()
{
    FixerObjet();
    animationdelobjet->stop();
    machine->stop();
}
int  ObjetMobile::ValeurPas() const { return pas;}
void ObjetMobile::DirectionGauche() { direction = Qt::Key_4;}
void ObjetMobile::DirectionDroite() { direction = Qt::Key_6;}
void ObjetMobile::DirectionHaut()   { direction = Qt::Key_8;}
void ObjetMobile::DirectionBas()    { direction = Qt::Key_2;}
int  ObjetMobile::CodeDirection()   { return direction;}
bool ObjetMobile::Immobile() const  { return direction == 0;}
bool ObjetMobile::Mobile() const    { return direction != 0;}
void ObjetMobile::PointCible(const QPointF cible)
{
    pntdep = pntfin;
    pntfin = cible;
    pntfin -= pntdep;
    if(pntfin.rx()==0)
        pntfin.setY(ValeurPas());
    else
        if(pntfin.ry()==0)
            pntfin.setX(ValeurPas());
        else
        {
            qreal angle = qAtan2(pntfin.ry(),pntfin.rx());
            pntfin.setX(pntdep.rx()+ValeurPas()*qCos(angle));
            pntfin.setY(pntdep.ry()+ValeurPas()*qSin(angle));
        }
}
void ObjetMobile::InitPas( int vpas ) { pas= vpas;}
void ObjetMobile::FixerObjet()        { direction = 0;}
bool ObjetMobile::TestCollision()     { return false;}
void ObjetMobile::MajMouvement()
{
        animationdelobjet->setEndValue(pntfin);
        animationdelobjet->start();
}
