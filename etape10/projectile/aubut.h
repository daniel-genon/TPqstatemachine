#ifndef AUBUT_H
#define AUBUT_H
#include "projectile.h"
class AuBut : public QState
{
public:
    AuBut(Projectile *vproj, QState *vparent=0);
protected:
    virtual void onEntry(QEvent *);
private:
    Projectile *projectile;
};
#endif // AUBUT_H
