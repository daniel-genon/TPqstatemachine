#ifndef SCENE_H
#define SCENE_H
#include <QToolButton>
#include <QLineEdit>
#include "../vue.h"
class Scene : public QGraphicsScene
{
Q_OBJECT
public:
    Scene(int x, int y, int width, int height);
    void InitialiserScene( QToolButton *nouvellepartie, QToolButton *quitterlejeu, QLineEdit *linformation);
    void NettoyerScene();
    void InitPtrVue(Vue *vptr);
    Vue *pVue() const;
    void ReInitialiserScene();

private:
    Vue *ptrvue;
};
#endif // SCENE_H
