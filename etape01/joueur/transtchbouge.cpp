#include "transtchbouge.h"

TransTchBouge::TransTchBouge(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{
    joueur = vjoueur;
    touche = k;
}
void TransTchBouge::onTransition(QEvent *)
{
    if(touche==Qt::Key_5)
        joueur->FixerObjet();
    else
        joueur->DirectionDroite();
}
