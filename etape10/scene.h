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
    void AjouterProjectile();

    Joueur      *pJoueur() const;
    Predateur   *pPredateur() const;
    Vue         *pVue() const;

private slots:
    void FinDeProjectile();
    void ButAtteint();

private:
    Joueur      *joueur;
    Predateur   *predateur;
    QList<Projectile*> lstprj;
    Vue         *ptrvue;
    void TuerProjectile();
};

#endif // SCENE_H
