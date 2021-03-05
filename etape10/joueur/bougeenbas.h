#ifndef BOUGEENBAS_H
#define BOUGEENBAS_H

#include "joueur.h"
class BougeEnBas : public QState
{
    Q_OBJECT
public:
    BougeEnBas( Joueur *vjoueur, QState *vparent = 0 );
protected:
    virtual void onEntry(QEvent *);
private:
    Joueur * joueur;
};

#endif // BOUGEENBAS_H
