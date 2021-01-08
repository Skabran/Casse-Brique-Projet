#include "balle.h"
#include "affichageJeu.h"


balle::balle(): elementMouvant{}, d_diametre{30.0} {}

balle::balle(double x, double y, double diametre): elementMouvant{x, y}, d_diametre{diametre} {}

balle::balle(const position& pos, double vitesse, double angle, double diametre):elementMouvant{pos, vitesse, angle},
d_diametre{diametre} {}

balle::balle(double x, double y, double vitesse, double angle, double diametre): elementMouvant{x, y, vitesse, angle},
d_diametre{diametre} {}

balle::~balle() = default;

double balle::getDiametre() const
{
    return d_diametre;
}


bool balle::testDeCollision(position posElementMouvant) {

}

void balle::effetCollision(elementMouvant *elementPercute)
{

}

void balle::effetCollision(element *elementPercute)
{

}

void balle::deplacer(){

}

void balle::afficheElement(const affichageJeu& affichage) const
{
    affichage.afficheBalle(*this);
}
