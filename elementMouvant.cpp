#include "elementMouvant.h"

elementMouvant::elementMouvant(): element{}, d_vecteurVitesse{} {}

elementMouvant::elementMouvant(double x, double y): element{x, y}, d_vecteurVitesse{} {}

elementMouvant::elementMouvant(double x, double y, double vitesse, double angle): element{x, y},
d_vecteurVitesse{vitesse, angle} {}

elementMouvant::~elementMouvant() = default;
