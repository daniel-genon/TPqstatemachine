#include "transdemarre.h"

TransDemarre::TransDemarre(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{ joueur = vjoueur; touche = k; }
void TransDemarre::onTransition(QEvent *)
{
    if(touche==Qt::Key_4)
        joueur->DirectionGauche();
    else
        joueur->DirectionDroite();
    joueur->VitesseInitiale();
}
