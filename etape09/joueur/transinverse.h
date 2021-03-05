#ifndef TRANSINVERSE_H
#define TRANSINVERSE_H

#include <QtWidgets/QKeyEventTransition>
#include "joueur.h"
class TransInverse : public QKeyEventTransition
{
    Q_OBJECT
public:
    TransInverse(Joueur *vjoueur, QEvent::Type t, int k);
protected:
    virtual bool eventTest(QEvent *evt);
    virtual void onTransition(QEvent *);
private:
    Joueur *joueur;
    int     touche;
};

#endif // TRANSINVERSE_H
