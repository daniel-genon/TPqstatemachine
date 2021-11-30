#ifndef TRANSETPAN_H
#define TRANSETPAN_H
#include <QKeyEventTransition>
#include "joueur.h"
class TransEtPan : public QKeyEventTransition
{
Q_OBJECT
public:
   TransEtPan(Joueur *vjoueur, QEvent::Type t, int k);
protected:
    virtual void onTransition(QEvent *);
private:
    Joueur *joueur;
};
#endif // TRANSETPAN_H
