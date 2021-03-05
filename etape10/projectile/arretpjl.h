#ifndef ARRETPJL_H
#define ARRETPJL_H
#include "projectile.h"
class ArretPjl : public QState
{
    Q_OBJECT
public:
    ArretPjl(Projectile *vprl, QState *vparent);
protected:
    virtual void onEntry(QEvent *);
private:
    Projectile *projectile;
};
#endif // ARRETPJL_H
