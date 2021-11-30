#ifndef PREDATEUR_H
#define PREDATEUR_H

#include "../../vue.h"
#include "../objetmobile.h"
#include "../joueur/joueur.h"

class Predateur : public ObjetMobile
{
public:
    Predateur(Joueur *valptr);
    void Initialiser(const QPointF& pdep);
    void MajMouvement();
    void InitPtrVue(Vue *vpvue );
    void PositionCible();
//public slots:
    virtual bool TestCollision();
private:
    Vue     *pvue;
    Joueur  *pjoueur;
};

#endif // PREDATEUR_H
