#include "deplacepjl.h"
DeplacePjl::DeplacePjl(Projectile *vproj, QState *vparent ) : QState(vparent)
{    projectile = vproj;}
void DeplacePjl::onEntry(QEvent *){ projectile->MajMouvement();}
