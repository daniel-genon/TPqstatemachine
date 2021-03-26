#include "transaccelere.h"

TransAccelere::TransAccelere(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{    joueur = vjoueur;}
bool TransAccelere::eventTest(QEvent *evt)
{
    if (!QKeyEventTransition::eventTest(evt)) return false;
    return !joueur->VitesseMaximale();
}
void TransAccelere::onTransition(QEvent *)
{
    joueur->AugmenterVitesse();
    joueur->MajMouvement();
}
