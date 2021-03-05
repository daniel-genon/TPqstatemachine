#include "deplaceprd.h"
DeplacePrd::DeplacePrd(Predateur *vpredat, QState *vparent ) : QState(vparent)
{
    predateur = vpredat;
}
DeplacePrd::~DeplacePrd(){}
void DeplacePrd::onEntry(QEvent *)
{
    predateur->MajMouvement();
}
