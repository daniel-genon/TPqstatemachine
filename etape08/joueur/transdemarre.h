#ifndef TRANSDEMARRE_H
#define TRANSDEMARRE_H

#include <QKeyEventTransition>
#include "joueur.h"
class TransDemarre : public QKeyEventTransition
{
Q_OBJECT
public:
    TransDemarre(Joueur *vjoueur, QEvent::Type t, int k);
protected:
    virtual void onTransition(QEvent *);
private:
    Joueur *joueur;
    int     touche;
};

#endif // TRANSDEMARRE_H
