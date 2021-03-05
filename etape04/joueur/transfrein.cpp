#include "transfrein.h"

TransFrein::TransFrein(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{    joueur = vjoueur; touche=k; }

void TransFrein::onTransition(QEvent *)
{
   joueur->DiminuerVitesse();
   joueur->MajMouvement();
}
