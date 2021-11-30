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
}
void ObjetMobile::BougeToi(){ if(!machine->isRunning()) { machine->start(); }}
void ObjetMobile::Stop()
{
    FixerObjet();
    animationdelobjet->stop();
    machine->stop();
}
int  ObjetMobile::ValeurPas() const       { return pas;}
void ObjetMobile::InitPas( int vpas )     { pas = vpas;}
void ObjetMobile::DirectionGauche()       { direction = Qt::Key_4;}
void ObjetMobile::DirectionDroite()       { direction = Qt::Key_6;}
void ObjetMobile::DirectionHaut()         { direction = Qt::Key_8;}
void ObjetMobile::DirectionBas()          { direction = Qt::Key_2;}
void ObjetMobile::FixerObjet()            { direction = 0;}
int  ObjetMobile::CodeDirection()         { return direction;}
bool ObjetMobile::Immobile() const        { return  direction == 0;}
bool ObjetMobile::Mobile() const          { return  direction != 0;}
bool ObjetMobile::VaADroite() const       { return  direction == Qt::Key_6;}
bool ObjetMobile::NeVaPasADroite() const  { return  direction != Qt::Key_6;}
bool ObjetMobile::VaAGauche() const       { return  direction == Qt::Key_4;}
bool ObjetMobile::NeVaPasAGauche() const  { return  direction != Qt::Key_4;}
bool ObjetMobile::VaEnHaut() const        { return  direction == Qt::Key_8;}
bool ObjetMobile::NeVaPasVaEnHaut() const { return  direction != Qt::Key_8;}
bool ObjetMobile::VaEnBas() const         { return  direction == Qt::Key_2;}
bool ObjetMobile::NeVaPasVaEnBas() const  { return  direction != Qt::Key_2;}
