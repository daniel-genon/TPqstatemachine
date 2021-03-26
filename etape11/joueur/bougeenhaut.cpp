#include "bougeenhaut.h"
BougeEnHaut::BougeEnHaut( Joueur *vjoueur, QState *vparent ) : QState(vparent)
{    joueur = vjoueur;}
void BougeEnHaut::onEntry(QEvent *)
{    joueur->MajMouvement();}
