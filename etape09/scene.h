#ifndef SCENE_H
#define SCENE_H

#include <QToolButton>
#include <QLineEdit>
#include "../vue.h"
#include "joueur/joueur.h"
#include "predateur/predateur.h"
#include "projectile/projectile.h"
class Scene : public QGraphicsScene
{
Q_OBJECT
public:
    Scene(int x, int y, int width, int height);
    ~Scene();
    void InitialiserScene(QToolButton *nouvellepartie, QToolButton *quitterlejeu, QLineEdit *linformation);
    void NettoyerScene();
    void ReInitialiserScene();
    void InitPtrVue(Vue *vptr);
    Joueur      *pJoueur() const;
    Predateur   *pPredateur() const;
    Projectile  *pProjectile() const;
    Vue         *pVue() const;
private:
    Joueur      *joueur;
    Predateur   *predateur;
    Projectile  *projectile;

    Vue         *ptrvue;
};

#endif // SCENE_H
