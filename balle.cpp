#include "balle.h"

balle::balle(): elementMouvant{}, d_rayon{1.0} {}

balle::balle(double x, double y, double rayon): elementMouvant{x, y}, d_rayon{rayon} {}

balle::balle(double x, double y, double vitesse, double angle, double rayon): elementMouvant{x, y, vitesse, angle},
d_rayon{rayon} {}

balle::~balle() = default;

bool balle::testDeCollision(position posElementMouvant) {

}

void balle::effetCollision(element *elementPercute)
{

}

void balle::deplacer(){

}
