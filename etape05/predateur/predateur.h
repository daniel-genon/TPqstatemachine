#ifndef PREDATEUR_H
#define PREDATEUR_H

#include "../../vue.h"
#include "objetmobile.h"
class Predateur : public ObjetMobile
{
public:
    Predateur();
    void Initialiser();
    void MajMouvement();
    void InitPtrVue(Vue *vpvue );
private:
    Vue *pvue;
    QPointF     pntfin;
    QPointF     pntdepart;
};

#endif // PREDATEUR_H
