#ifndef TRANSFREIN_H
#define TRANSFREIN_H
#include <QtWidgets/QKeyEventTransition>
#include "joueur.h"
class TransFrein : public QKeyEventTransition
{
    Q_OBJECT
public:
    TransFrein(Joueur *vjoueur, QEvent::Type t, int k);
protected:
    virtual void onTransition(QEvent *);
private:
    Joueur *joueur;
    int     touche;
};
#endif // TRANSFREIN_H
