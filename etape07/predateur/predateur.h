#ifndef PREDATEUR_H
#define PREDATEUR_H

#include "../../vue.h"
#include "objetmobile.h"
class Predateur : public ObjetMobile
{
public:
    Predateur();
    void Initialiser( const QPointF &pdep, const QPointF &pfin);
    void ReInitialiser();
    void MajMouvement();
    void InitPtrVue(Vue *vpvue );
private:
    Vue     *pvue;
    QPointF  pntdepart, pntfin, pntfinsvd, pntdepsvd;

};

#endif // PREDATEUR_H
