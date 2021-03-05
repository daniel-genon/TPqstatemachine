#ifndef TRANSTCHSTOPDEPL_H
#define TRANSTCHSTOPDEPL_H

#include <QtWidgets/QKeyEventTransition>
#include "objetsmobiles/joueur/joueur.h"
class TransTchStop : public QKeyEventTransition
{
public:
    TransTchStop(Joueur *vjoueur, QEvent::Type t,
                                              int k);
protected:
    virtual bool eventTest(QEvent *evt);
    virtual void onTransition(QEvent *event);
private:
    Joueur * joueur;
    int touche;
};

#endif // TRANSTCHSTOPDEPL_H
