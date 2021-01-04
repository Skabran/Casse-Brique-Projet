#include "raquette.h"

raquette::raquette(): elementMouvant{}, d_longueur{4.0}, d_largeur{2.0} {}

raquette::raquette(double x, double y, double longueur, double largeur): elementMouvant{x, y},
d_longueur{longueur}, d_largeur{largeur} {}

raquette::~raquette() = default;

bool raquette::testDeCollision(position posElementMouvant) {

}

void raquette::effetCollision(element *elementPercute)
{

}


void raquette::deplacer(){

}

void raquette::afficheElement() const
{

}

/*
void raquette::miseAJour()
{
    "deplacement vélocité";
    if(Keyboard::isKeyPressed(Keyboard::Key::Left) && gauche() > 0)
        vélocité.x = -vélocitéRaquette;
    else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && droite() < longueurFenetre)
        vélocité.x = vélocitéRaquette;
        else
            vélocité.x = 0;
}

*/

