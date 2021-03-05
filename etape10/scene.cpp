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
    joueur = new(Joueur);
    joueur->hide();
    addItem(joueur);
    predateur = new Predateur(joueur);
    predateur->hide();
    addItem(predateur);
}
Scene::~Scene()
{
    if (joueur)     delete joueur;
    if (predateur)  delete predateur;
    TuerProjectile();
}
void Scene::AjouterProjectile()
{
    Projectile *pproj = new Projectile(predateur, joueur);
    pproj->hide();
    lstprj.append(pproj);
    addItem(pproj);
    connect(pproj, SIGNAL(Boum()), this, SLOT(ButAtteint()));
    connect(pproj, SIGNAL(Limite()), this, SLOT(FinDeProjectile()));
    pproj->Tirer();
}
void Scene::TuerProjectile()
{
    if(!lstprj.empty())
    {
        for(int i=0;i<lstprj.size();++i){ delete lstprj.at(i);}
        lstprj.clear();
    }

}
void Scene::ButAtteint(){ FinDeProjectile();}
void Scene::FinDeProjectile()
{
    Projectile *pproj = qobject_cast<Projectile *>(sender());
    if(pproj)
    {
        lstprj.removeOne(pproj);
        pproj->deleteLater();
    }
}
void Scene::InitialiserScene( QToolButton *nouvellepartie, QToolButton *quitterlejeu, QLineEdit *linformation)
{
    linformation->setText("un objet produit et démarre une série d'objets");
    predateur->Initialiser(QPointF(0,0));
    QStateMachine *machine = new QStateMachine(this);
    ZoneAnime *zoneanime=new ZoneAnime(this, machine);
    QFinalState *final = new QFinalState(machine);
    zoneanime->addTransition(nouvellepartie, SIGNAL(clicked()), zoneanime);
    zoneanime->addTransition(quitterlejeu, SIGNAL(clicked()), final);
    connect(machine, SIGNAL(finished()), qApp, SLOT(quit()));
    machine->setInitialState(zoneanime);
    machine->start();
}
void Scene::NettoyerScene()
{
    joueur->Stop();
    joueur->hide();
    joueur->setEnabled(true);
    predateur->Stop();
    predateur->hide();
    predateur->setEnabled(true);
    TuerProjectile();
}
void Scene::ReInitialiserScene()
{
    setFocusItem(joueur, Qt::OtherFocusReason);
    joueur->ReInitialiser();
    predateur->Initialiser(QPointF(0,0));
    TuerProjectile();
}
void Scene::InitPtrVue(Vue *vptr)
{
    ptrvue = vptr;
    joueur->InitPtrVue( vptr );
    predateur->InitPtrVue( vptr );
}
Vue *Scene::pVue() const             { return ptrvue;}
Joueur *Scene::pJoueur() const       { return joueur;}
Predateur *Scene::pPredateur() const { return predateur; }

