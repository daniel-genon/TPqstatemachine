#ifndef OBJETMOBILE_H
#define OBJETMOBILE_H

#include "../objetimage.h"
#include <QVariantAnimation>
#include <QStateMachine>
class ObjetMobile : public ObjetImage
{
Q_OBJECT
public:
    ObjetMobile();
    ~ObjetMobile();
    void BougeToi();
    void Stop();
    int ValeurPas() const;
    void DirectionDroite();
    void DirectionGauche();
    void DirectionHaut();
    void DirectionBas();
    int CodeDirection();
    bool Immobile() const;
    bool Mobile() const;
    virtual void InitPas( int vpas );
    virtual void FixerObjet();
    virtual bool TestCollision();
protected:
    QVariantAnimation  *animationdelobjet;
    QStateMachine      *machine;
    QPointF             pntdep, pntfin;
    void PointCible(const QPointF cible);
private:
    int  direction;
            //0=fixe, gah=Qt::Key_4, drt=Qt::Key_6,
            //        hau=Qt::Key_8, bas=Qt::Key_2
    int  pas;
};

#endif // OBJETMOBILE_H
