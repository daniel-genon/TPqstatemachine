#ifndef TRANSACCELERE_H
#define TRANSACCELERE_H

#include <QtWidgets/QKeyEventTransition>
#include "joueur.h"
class TransAccelere : public QKeyEventTransition
{
public:
    TransAccelere(Joueur *vjoueur, QEvent::Type t, int k);
protected:
    virtual void onTransition(QEvent *);
private:
    Joueur *joueur;
};
#endif // TRANSACCELERE_H
