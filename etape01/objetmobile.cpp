#include "objetmobile.h"
ObjetMobile::ObjetMobile()
{
    pas=10;
    direction = 0;
    animationdelobjet = 0;
    machine=0;
}
ObjetMobile::~ObjetMobile()
{
    if(machine)
    {
        machine->stop();
        delete machine;
    }
    if (animationdelobjet)  {   delete animationdelobjet;}
}
void ObjetMobile::BougeToi(){ machine->start();}
void ObjetMobile::Stop()
{
    FixerObjet();
    animationdelobjet->stop();
    machine->stop();
}
quint8 ObjetMobile::ValeurPas() const    { return pas;}
void ObjetMobile::InitPas(quint8 vpas )  { pas = vpas;}
void ObjetMobile::DirectionDroite()      { direction = Qt::Key_6;}
void ObjetMobile::FixerObjet()           { direction =0;}
bool ObjetMobile::Immobile() const       { return direction==0;}
bool ObjetMobile::Mobile() const         { return direction != 0;}
bool ObjetMobile::VaADroite() const      { return direction == Qt::Key_6;}
bool ObjetMobile::NeVaPasADroite() const { return direction != Qt::Key_6;}
