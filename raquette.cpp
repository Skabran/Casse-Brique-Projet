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



/*
rectangle::rectangle(double coordX, double coordY):d_x{coordX}, d_y{coordY}, d_longueur{longueurRectangle}, d_largeur{largeurRectangle}, d_color{BLUE}
{

}

double rectanle::x() const
{
    return d_x;
}

double rectanle::y() const
{
    return d_y;
}

double rectangle::gauche()
{
    return x() - d_longueur/2;
}

double rectangle::droite()
{
    return x() + d_longueur/2;
}

double rectangle::haut()
{
    return y() - d_largeur/2;
}

double rectangle::bas()
{
    return y() + d_largeur/2;
}

raquette::raquette():d_x{longueurRaquette/2}, d_y{largeurRaquette/2}, d_longueur{longueurRaquette}, d_largueur{largeurRaquette}, d_color{RED}
{

}

raquette::raquette(double coordX, double coordY):d_x{coordX}, d_y{coordY}, d_longueur{longueurRectangle}, d_largueur{largeurRectangle}, d_color{RED}
{

}

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

