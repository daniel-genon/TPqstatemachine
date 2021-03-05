#include "transaccelere.h"

TransAccelere::TransAccelere(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{    joueur = vjoueur;}
void TransAccelere::onTransition(QEvent *)
{   joueur->AugmenterVitesse();}
