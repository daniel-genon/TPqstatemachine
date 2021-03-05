#include "arretpjl.h"
ArretPjl::ArretPjl(Projectile *vprl, QState *vparent) : QState(vparent)
{    projectile=vprl; }
void ArretPjl::onEntry(QEvent *){ projectile->Foirer(); }
