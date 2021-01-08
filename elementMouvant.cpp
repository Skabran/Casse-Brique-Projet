#include "elementMouvant.h"


elementMouvant::elementMouvant(): element{}, d_vecteurVitesse{} {}

elementMouvant::elementMouvant(double x, double y): element{x, y}, d_vecteurVitesse{} {}

elementMouvant::elementMouvant(double x, double y, double vitesse, double angle): element{x, y},
d_vecteurVitesse{vitesse, angle} {}

elementMouvant::elementMouvant(position pos, double vitesse, double angle) : element{pos}, d_vecteurVitesse{vitesse, angle} {}

elementMouvant::elementMouvant(position pos, vecteur vect):element{pos}, d_vecteurVitesse{vect} {}

elementMouvant::~elementMouvant() = default;

vecteur elementMouvant::getVecteur() const
{
    return d_vecteurVitesse;
}

void elementMouvant::changeVecteur(const vecteur& vect)
{
    d_vecteurVitesse=vect;
}

elementMouvant& elementMouvant::operator=(const elementMouvant& elem)
{
    changePosition(elem.getPosition());
    d_vecteurVitesse=elem.getVecteur();
}
