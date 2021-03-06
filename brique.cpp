#include "brique.h"
#include "affichageJeu.h"


brique::brique(): element{}, d_longueur{60.0}, d_largeur{30.0} {}

brique::brique(double x, double y, double longueur, double largeur): element{x, y},
d_longueur{longueur}, d_largeur{largeur} {}

brique::~brique() = default;


double brique::getLongueurBrique() const
{
    return d_longueur;
}


double brique::getLargeurBrique() const
{
    return d_largeur;
}


bool brique::testDeCollision(position posElementMouvant) {

}

void brique::effetCollision(elementMouvant *elementPercute)
{

}


void brique::afficheElement(const affichageJeu& affichage) const
{
    affichage.afficheBrique(*this);
}
