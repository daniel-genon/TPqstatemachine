#include "arretprd.h"
ArretPrd::ArretPrd(Predateur *vprd, QState *vparent) : QState(vparent)
{    predateur = vprd;}
ArretPrd::~ArretPrd(){}
void ArretPrd::onEntry(QEvent *)
{
    predateur->ReInitialiser();
    emit RePositionner();
}
