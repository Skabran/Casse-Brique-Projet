#include "balle.h"
#include "affichageJeu.h"


balle::balle(): elementMouvant{}, d_rayon{1.0} {}

balle::balle(double x, double y, double rayon): elementMouvant{x, y}, d_rayon{rayon} {}

balle::balle(double x, double y, double vitesse, double angle, double rayon): elementMouvant{x, y, vitesse, angle},
d_rayon{rayon} {}

balle::~balle() = default;

double balle::getRayon() const
{
    return d_rayon;
}


bool balle::testDeCollision(position posElementMouvant) {

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
