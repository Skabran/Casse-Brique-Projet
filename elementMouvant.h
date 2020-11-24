#ifndef ELEMENTMOUVANT_H
#define ELEMENTMOUVANT_H
#include "element.h"
#include "vecteur.h"

class elementMouvant : public element {
public:
    elementMouvant();
    virtual ~elementMouvant();
    virtual void deplacer() = 0;

private:
    vecteur d_vecteurVitesse;
};

#endif // ELEMENTMOUVANT_H
