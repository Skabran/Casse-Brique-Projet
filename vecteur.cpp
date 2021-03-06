#include "vecteur.h"

vecteur::vecteur(): d_vitesse{1.0}, d_angle{0.0} {}

vecteur::vecteur(double vitesse, double angle): d_vitesse{vitesse}, d_angle{angle} {}

vecteur::~vecteur()= default;

double vecteur::getVitesse() const{
    return d_vitesse;
}

double vecteur::getAngle() const{
    return d_angle;
}

void vecteur::changeVitesse(double vitesse)
{
    d_vitesse=vitesse;
}

void vecteur::changeAngle(double angle)
{
    d_angle=angle;
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


vecteur& vecteur::operator=(const vecteur& vect)
{
    d_vitesse=vect.getVitesse();
    d_angle=vect.getAngle();
}


vecteur operator*(double coef, vecteur& vect){
    vect.multiplieVitesse(coef);
    return vect;
}
