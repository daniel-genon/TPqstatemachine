#ifndef JOUEUR_H
#define JOUEUR_H

#include "../../vue.h"
#include "objetmobile.h"
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
    void MajMouvement();
    void InitPtrVue(Vue *vpvue );

//Ajout pour défilement de l'image du fond quand le joueur bouge 26-03-21
private slots:
    void LeJoueurBouge(const QVariant &);

private:
    quint8      vitesse;
    quint8      limitevitesse;
    quint8      acceleration;
    quint8      coefresiste;
    Vue         *pvue;
    QPointF     npos;
};

#endif // JOUEUR_H
