#include "transdemarre.h"

TransDemarre::TransDemarre(Joueur *vjoueur, QEvent::Type t, int k) : QKeyEventTransition(vjoueur, t, k)
{    joueur = vjoueur; touche=k; }
void TransDemarre::onTransition(QEvent *)
{
    switch(touche)
    {
    case Qt::Key_4 :{joueur->DirectionGauche();}break;
    case Qt::Key_6 :{joueur->DirectionDroite();}break;
    case Qt::Key_8 :{joueur->DirectionHaut();}break;
    case Qt::Key_2 :{joueur->DirectionBas();}break;
    }
    joueur->VitesseInitiale();
}
