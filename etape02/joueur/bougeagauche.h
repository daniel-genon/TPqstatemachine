#ifndef BOUGEAGAUCHE_H
#define BOUGEAGAUCHE_H

#include "joueur.h"
class BougeAGauche : public QState
{
    Q_OBJECT
public:
    BougeAGauche( Joueur *vjoueur, QState *vparent = 0 );
protected:
    virtual void onEntry(QEvent *);
private:
    Joueur * joueur;
};

#endif // BOUGEAGAUCHE_H
