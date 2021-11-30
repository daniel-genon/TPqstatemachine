#include "aubut.h"
AuBut::AuBut(Projectile *vprl, QState *vparent) : QState(vparent)
{    projectile=vprl; }
void AuBut::onEntry(QEvent *){ projectile->Detruire();}
