#ifndef SCENE_H
#define SCENE_H

#include <QToolButton>
#include <QLineEdit>
#include "../vue.h"
#include "predateur/predateur.h"
class Scene : public QGraphicsScene
{
Q_OBJECT
public:
    Scene(int x, int y, int width, int height);
    ~Scene();
    void InitialiserScene( QToolButton *nouvellepartie, QToolButton *quitterlejeu, QLineEdit *linformation);
    void NettoyerScene();
    void ReInitialiserScene();
    void InitPtrVue(Vue *vptr);
    Predateur   *pPredateur(quint8 indice) const;
    Vue         *pVue() const;
private:
    QList<Predateur*> lstpred;
    Vue         *ptrvue;

    void IniPredateur();
};

#endif // SCENE_H
