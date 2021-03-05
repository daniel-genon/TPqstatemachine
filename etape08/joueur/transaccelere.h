#ifndef TRANSACCELERE_H
#define TRANSACCELERE_H

#include <QtWidgets/QKeyEventTransition>
#include "joueur.h"
class TransAccelere : public QKeyEventTransition
{
    Q_OBJECT
public:
    TransAccelere(Joueur *vjoueur, QEvent::Type t, int k);
protected:
    virtual bool eventTest(QEvent *evt);
    virtual void onTransition(QEvent *);
private:
    Joueur *joueur;
};
#endif // TRANSACCELERE_H
