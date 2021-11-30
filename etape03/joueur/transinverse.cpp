#include "transinverse.h"

TransInverse::TransInverse(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{
    joueur = vjoueur;
    touche = k;
}
bool TransInverse::eventTest(QEvent *evt)
{
    if (!QKeyEventTransition::eventTest(evt)) return false;

 return((touche == Qt::Key_4 && joueur->VaADroite())
             ||
        (touche == Qt::Key_6 && joueur->VaAGauche())
       )
             &&
        joueur->VitesseMinimale();
}
void TransInverse::onTransition(QEvent *)
{   joueur->InverserDeplacement();}
