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
    quint8 ValeurPas() const;
    void InitPas( quint8 vpas );
    void DirectionDroite();
    void DirectionGauche();
    int  CodeDirection();
    bool Immobile() const;
    bool Mobile() const;
    bool VaADroite() const;
    bool NeVaPasADroite() const;
    bool VaAGauche() const;
    bool NeVaPasAGauche() const;
    virtual void FixerObjet();
protected:
    QVariantAnimation *animationdelobjet;
    QStateMachine *machine;
private:
    int  direction;
    //0=fixe, gah=Qt::Key_4, drt=Qt::Key_6,
    //        hau=Qt::Key_8, bas=Qt::Key_2
    quint8 pas;
};

#endif // OBJETMOBILE_H
