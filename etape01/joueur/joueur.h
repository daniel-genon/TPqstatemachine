#ifndef JOUEUR_H
#define JOUEUR_H

#include "../vue.h"
#include "objetmobile.h"
class Joueur : public ObjetMobile
{
Q_OBJECT
public:
    Joueur();
    void ReInitialiser();
    void MajMouvement();
    void InitPtrVue(Vue *vpvue );
signals:
    void joueurDestroyed();
private:
    Vue        *pvue;
    QPointF     npos;
};

#endif // JOUEUR_H
