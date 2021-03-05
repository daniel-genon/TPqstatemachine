#include "bougeadroite.h"
BougeADroite::BougeADroite( Joueur *vjoueur, QState *vparent ) : QState(vparent)
{    joueur = vjoueur;}
void BougeADroite::onEntry(QEvent *)
{    joueur->MajMouvement();}
