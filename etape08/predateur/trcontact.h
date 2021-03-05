#ifndef TRCONTACT_H
#define TRCONTACT_H
#include <QSignalTransition>
//#include "predateur.h"
#include "deplaceprd.h"
class TrContact : public QSignalTransition
{
public:
    TrContact(Predateur *vpredat, DeplacePrd *vdepl);
protected:
    virtual void onTransition(QEvent *);
private:
    Predateur *predateur;
};
#endif // TRCONTACT_H
