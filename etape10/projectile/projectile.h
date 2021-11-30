#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "../../vue.h"
#include "predateur/predateur.h"
#include "objetmobile.h"
class Projectile : public ObjetMobile
{
Q_OBJECT
public:
    Projectile(Predateur *pcbl, Joueur *pstir);
    ~Projectile();
    void Tirer();
    void Detruire();
    void Foirer();
    virtual bool TestCollision();

signals:
    void Boum();
    void Limite();
    void Contact();

private slots:
    void LeProjectileBouge(const QVariant &);

private:
    Vue       *pvue;
    Predateur *pcible;
    Joueur    *pjoueur;
};
#endif // PROJECTILE_H
