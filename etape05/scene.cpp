#include "scene.h"
#include <QtCore/QStateMachine>
#include <QtCore/QFinalState>
#include <QtWidgets/QApplication>
#include "../zoneanime.h"
Scene::Scene(int x, int y, int width, int height) : QGraphicsScene(x , y, width, height)
{
    ObjetImage *fondItem = new ObjetImage( QString(":/motif/fond1.png"));
    fondItem->setZValue(1);
    fondItem->setPos(0,0);
    addItem(fondItem);
    predateur = new(Predateur);
    addItem(predateur);
    predateur->hide();
}
Scene::~Scene(){   delete predateur;}
void Scene::InitialiserScene( QToolButton *nouvellepartie, QToolButton *quitterlejeu, QLineEdit *linformation)
{
    linformation->setText("objet libre");
    QStateMachine *machine =new QStateMachine(this);
    ZoneAnime *zoneanime = new ZoneAnime(this, machine );
    QFinalState *final = new QFinalState( machine );
    zoneanime->addTransition(nouvellepartie, SIGNAL(clicked()), zoneanime );
    zoneanime->addTransition(quitterlejeu, SIGNAL(clicked()), final );
    connect(machine, SIGNAL(finished()), qApp, SLOT(quit()));
    machine->setInitialState(zoneanime);
    machine->start();
}
void Scene::NettoyerScene()
{
    predateur->Stop();
    predateur->hide();
    predateur->setEnabled(true);
}
void Scene::ReInitialiserScene()
{
    setFocusItem(predateur, Qt::OtherFocusReason);
    predateur->Initialiser();
    predateur->BougeToi();
}
void Scene::InitPtrVue(Vue *vptr)
{
    ptrvue = vptr;
    predateur->InitPtrVue(vptr);
}
Vue *Scene::pVue() const{ return ptrvue;}
