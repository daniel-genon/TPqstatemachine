#ifndef BOUGEADROITE_H
#define BOUGEADROITE_H

#include "joueur.h"
class BougeADroite : public QState
{
public:
    BougeADroite( Joueur *vjoueur, QState *vparent = 0 );
protected:
    virtual void onEntry(QEvent *);
private:
    Joueur * joueur;
};

#endif // BOUGEADROITE_H
