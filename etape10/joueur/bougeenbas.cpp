#include "bougeenbas.h"
BougeEnBas::BougeEnBas( Joueur *vjoueur, QState *vparent ) : QState(vparent)
{    joueur = vjoueur;}
void BougeEnBas::onEntry(QEvent *)
{    joueur->MajMouvement();}
