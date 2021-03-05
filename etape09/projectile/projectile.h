#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "../../vue.h"
#include "../joueur/joueur.h"
#include "../objetmobile.h"
class Projectile : public ObjetMobile
{
Q_OBJECT
public:
    Projectile(QGraphicsItem *pcbl, Joueur *pstir);
    ~Projectile();
    void Initialiser();
    void Tirer();
    void InitPtrVue(Vue *vpvue );
    virtual bool TestCollision();

signals:
    void Choc();
private slots:
    void LeProjectileBouge(const QVariant &);

private:
    Vue             *pvue;
    QGraphicsItem   *pcible;
    Joueur          *pjoueur;
};
#endif // PROJECTILE_H
