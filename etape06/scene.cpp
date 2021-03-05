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
    for (int i=0;i<3;++i)
    {
        lstpred.append(new(Predateur));
        lstpred.last()->hide();
        addItem(lstpred.last());
    }
}
Scene::~Scene()
{
    if(!lstpred.empty())
    {
        for(int i=0;i<lstpred.size();++i) { delete lstpred.at(i); }
        lstpred.clear();
    }
}
void Scene::InitialiserScene( QToolButton *nouvellepartie, QToolButton *quitterlejeu, QLineEdit *linformation)
{
    linformation->setText("série d'objets libres");
    IniPredateur();
    QStateMachine *machine = new QStateMachine(this);
    ZoneAnime *zoneanime=new ZoneAnime(this,machine);
    QFinalState *final = new QFinalState(machine);
    zoneanime->addTransition(nouvellepartie, SIGNAL(clicked()), zoneanime);
    zoneanime->addTransition(quitterlejeu, SIGNAL(clicked()), final);
    connect(machine, SIGNAL(finished()), qApp, SLOT(quit()));
    machine->setInitialState(zoneanime);
    machine->start();
}
void Scene::NettoyerScene()
{
    for(int i=0;i<lstpred.size();++i)
    {
        lstpred.at(i)->Stop();
        lstpred.at(i)->hide();
        lstpred.at(i)->setEnabled(true);
    }
}
void Scene::ReInitialiserScene()
{
    for(int i=0;i<lstpred.size();++i)
    {
        lstpred.at(i)->ReInitialiser();
    }
}
void Scene::InitPtrVue(Vue *vptr)
{
    ptrvue = vptr;
     for(int i=0;i<lstpred.size();++i)
    {
        lstpred.at(i)->InitPtrVue( vptr );
    }
}
Vue *Scene::pVue() const {            return ptrvue;}
Predateur *Scene::pPredateur(quint8 indice) const
{
    if(indice>=1 && indice<lstpred.size())
        return lstpred.at(indice);
    else
        return NULL;
}
void Scene::IniPredateur()
{
    if(!lstpred.isEmpty())
    {
        int lp=lstpred.first()->size().width();
        int hp=lstpred.first()->size().height();
        int lg=width()+lp;
        int hg=height()+hp;
        lstpred.first()->Initialiser(QPointF(-lp,-hp), QPointF(lg/2,hg));
        lstpred.first()->InitPas(1000);
        lstpred.at(1)->Initialiser(QPointF(-lp,hg/2), QPointF(lg-50,-hp));
        lstpred.at(1)->InitPas(4000);
        lstpred.at(2)->Initialiser(QPointF(lg,hg), QPointF(lg-200,-hp));
        lstpred.at(2)->InitPas(8000);
    }
}
