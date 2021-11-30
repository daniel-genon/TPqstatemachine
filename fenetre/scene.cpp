#include "scene.h"
#include <QStateMachine>
#include <QFinalState>
#include <QtWidgets/QApplication>
#include "../objetimage.h"
#include "../zoneanime.h"
Scene::Scene( int x, int y, int width, int height ):QGraphicsScene(x , y, width, height)
{
    ObjetImage *fondItem = new ObjetImage(QString(":/motif/fond1.png"));
    fondItem->setZValue(1);
    fondItem->setPos(0,0);
    addItem(fondItem);
}
void Scene::InitialiserScene( QToolButton *nouvellepartie, QToolButton *quitterlejeu, QLineEdit *linformation)
{
    linformation->setText("fenêtre de test pour la programmation de base avec QStateMachine");
    QStateMachine *machine =new QStateMachine(this);
    ZoneAnime *zoneanime = new ZoneAnime( this, machine );
    QFinalState *final = new QFinalState( machine );
    zoneanime->addTransition( nouvellepartie, SIGNAL(clicked()), zoneanime );
    zoneanime->addTransition( quitterlejeu,   SIGNAL(clicked()), final );
    connect(machine, SIGNAL(finished()), qApp, SLOT(quit()));
    machine->setInitialState(zoneanime);
    machine->start();
}
void Scene::NettoyerScene(){}
void Scene::ReInitialiserScene(){NettoyerScene();}
void Scene::InitPtrVue(Vue *vptr){ptrvue = vptr;}
Vue *Scene::pVue() const{ return ptrvue;}
