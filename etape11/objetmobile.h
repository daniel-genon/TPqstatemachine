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
    int  ValeurPas() const;
    void DirectionDroite();
    void DirectionGauche();
    void DirectionHaut();
    void DirectionBas();
    int  CodeDirection();
    bool Immobile() const;
    bool Mobile() const;
    bool VaADroite() const;
    bool NeVaPasADroite() const;
    bool VaAGauche() const;
    bool NeVaPasAGauche() const;
    bool VaEnHaut() const;
    bool NeVaPasVaEnHaut() const;
    bool VaEnBas() const;
    bool NeVaPasVaEnBas() const;
    virtual void InitPas( int vpas );
    virtual void FixerObjet();
protected:
    QVariantAnimation *animationdelobjet;
    QStateMachine *machine;
private:
    int direction;
    //0=fixe, gah=Qt::Key_4, drt=Qt::Key_6,
    //        hau=Qt::Key_8, bas=Qt::Key_2
    int pas;
};

#endif // OBJETMOBILE_H
