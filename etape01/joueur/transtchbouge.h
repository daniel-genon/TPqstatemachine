#ifndef TRANSTCHBOUGE_H
#define TRANSTCHBOUGE_H

#include <QKeyEventTransition>
#include "joueur.h"
class TransTchBouge : public QKeyEventTransition
{
public:
    TransTchBouge(Joueur *vjoueur, QEvent::Type t, int k);
protected:
    virtual void onTransition(QEvent *);
 private:
    Joueur *joueur;
    int     touche;
};

#endif // TRANSTCHBOUGE_H
