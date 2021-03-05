#include "transtchstop.h"
TransTchStop::TransTchStop(Joueur *vjoueur,
                             QEvent::Type t, int k) :
                   QKeyEventTransition(vjoueur, t, k)
{
    joueur = vjoueur;
    touche = k;
}
bool TransTchStop::eventTest(QEvent *evt)
{
    if (!QKeyEventTransition::eventTest(evt))
        return false;

    return touche==Qt::Key_5;
}
void TransTchStop::onTransition(QEvent *evt)
{
    joueur->FixerObjet();
}

