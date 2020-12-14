#include "vecteur.h"

vecteur::vecteur(): d_vitesse{}, d_angle{} {}

vecteur::vecteur(double vitesse, double angle): d_vitesse{vitesse}, d_angle{angle} {}

vecteur::~vecteur()= default;



double vecteur::getAngle() const{
    return d_angle;
}

double vecteur::getVitesse() const{
    return d_vitesse;
}

void vecteur::multiplieVitesse(double coef){
    d_vitesse*=coef;
}

void vecteur::inverseHorizontale(){
    d_angle=-d_angle;
}

void vecteur::inverseVertical(){
    d_angle=180-d_angle;
}


vecteur vecteur::operator*(double coef){
    d_vitesse*=coef;
    return *this;
}


vecteur operator*(double coef, vecteur& vect){
    vect.multiplieVitesse(coef);
    return vect;
}
