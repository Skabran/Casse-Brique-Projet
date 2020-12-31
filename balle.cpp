#include "balle.h"

balle::balle(): elementMouvant{}, d_rayon{1.0} {}

balle::balle(double x, double y, double rayon): elementMouvant{x, y}, d_rayon{rayon} {}

balle::balle(double x, double y, double vitesse, double angle, double rayon): elementMouvant{x, y, vitesse, angle},
d_rayon{rayon} {}

balle::~balle() = default;

bool balle::collision(position posElementMouvant) {

}

void balle::deplacer(){

}

/*
balle::balle() : d_x{5}, d_y{5}, d_rayon{5}, d_color{RED}
{

}

balle::balle(double coordX, coordY) : d_x{coordX}, d_y{coordY}, d_rayon{5}, d_color{RED}
{

}

void balle::miseAJour()
{
    "deplacementBalle(vélocité)";
    if(gauche() < 0)
        "vélocité.x=vélocitéBalle";
    else if(droite() > largeurFenetre)
        "velocité.x=-vélocitéBalle";
}

double balle::x()
{
    return d_x;
}

double balle::y()
{
    return d_y;
}

double balle::gauche()
{
    return x() - d_rayon;
}

double balle::droite()
{
    return x() + d_rayon;
}

double balle::haut()
{
    return y() - d_rayon;
}

double balle::bas()
{
    return y() + d_rayon;
}
*/
