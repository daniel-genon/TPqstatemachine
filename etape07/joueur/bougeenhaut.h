#ifndef BOUGEENHAUT_H
#define BOUGEENHAUT_H

#include "joueur.h"
class BougeEnHaut : public QState
{
    Q_OBJECT
public:
    BougeEnHaut( Joueur *vjoueur, QState *vparent = 0 );
protected:
    virtual void onEntry(QEvent *);
private:
    Joueur *joueur;
};

#endif // BOUGEENHAUT_H
