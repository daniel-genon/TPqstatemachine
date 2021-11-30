#include "trcontact.h"
TrContact::TrContact(Predateur *vpredat, DeplacePrd *vdepl) : QSignalTransition(vdepl,SIGNAL(Percussion()))
{    predateur=vpredat;}
void TrContact::onTransition(QEvent *) { predateur->Initialiser(QPointF(0,0));}
