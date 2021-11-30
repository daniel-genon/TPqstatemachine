#ifndef DEPLACEPRD_H
#define DEPLACEPRD_H

#include "predateur.h"
class DeplacePrd : public QState
{
    Q_OBJECT
public:
    DeplacePrd(Predateur *vpredat, QState *vparent=0);
    ~DeplacePrd();
protected:
    virtual void onEntry(QEvent *);
private:
    Predateur * predateur;
};

#endif // DEPLACEPRD_H
