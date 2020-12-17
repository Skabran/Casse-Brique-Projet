#ifndef ELEMENTMOUVANT_H
#define ELEMENTMOUVANT_H
#include "element.h"
#include "vecteur.h"

class elementMouvant : public element {
public:
    elementMouvant();
    elementMouvant(double x, double y);
    elementMouvant(double x, double y, double vitesse, double angle);
    virtual ~elementMouvant();
    virtual void deplacer() = 0;
    virtual bool collision() override = 0;

private:
    vecteur d_vecteurVitesse;
};

#endif // ELEMENTMOUVANT_H
