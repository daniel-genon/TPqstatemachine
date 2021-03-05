#include "transetpan.h"
TransEtPan::TransEtPan(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{    joueur = vjoueur;}
void TransEtPan::onTransition(QEvent *) { joueur->Tirer();}
