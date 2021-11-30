#ifndef DEPLACEPJL_H
#define DEPLACEPJL_H
#include "projectile.h"
class DeplacePjl : public QState
{
Q_OBJECT
public:
    DeplacePjl(Projectile *vproj, QState *vparent=0);
protected:
    virtual void onEntry(QEvent *);
private:
    Projectile *projectile;
};
#endif // DEPLACEPJL_H
