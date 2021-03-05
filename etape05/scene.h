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
    Vue *pVue() const;
private:
    Predateur *predateur;
    Vue *ptrvue;
};

#endif // SCENE_H
