#ifndef ARRETPRD_H
#define ARRETPRD_H

#include "predateur.h"
class ArretPrd : public QState
{
    Q_OBJECT
public:
    ArretPrd( Predateur *vprd, QState *vparent = 0 );
    ~ArretPrd();
signals :
    void RePositionner();
protected:
    virtual void onEntry(QEvent *);
private:
    Predateur *predateur;
};

#endif // ARRETPRD_H
