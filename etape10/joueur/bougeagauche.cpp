#include "bougeagauche.h"
BougeAGauche::BougeAGauche( Joueur *vjoueur, QState *vparent ) : QState(vparent)
{    joueur = vjoueur;}
void BougeAGauche::onEntry(QEvent *)
{    joueur->MajMouvement();}
