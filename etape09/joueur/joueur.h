#ifndef JOUEUR_H
#define JOUEUR_H
#include "../../vue.h"
#include "../objetmobile.h"
class Joueur : public ObjetMobile
{
Q_OBJECT
public:
    Joueur();
    void ReInitialiser();
    void AnnulerVitesse();
    void AugmenterVitesse();
    void DiminuerVitesse();
    void VitesseInitiale();
    quint8  Vitesse() const;
    bool    VitesseNulle() const;
    bool    VitessePasNulle() const;
    bool    VitesseMinimale() const;
    bool    VitesseMaximale() const;
    void InitPtrVue(Vue *vpvue );
    void Tirer();
    virtual void MajMouvement();
signals:
    void OrdreDeTir();
private:
    quint8      vitesse;
    quint8      limitevitesse;
    quint8      acceleration;
    quint8      coefresiste;
    Vue         *pvue;
    QPointF     npos;
};
#endif // JOUEUR_H
