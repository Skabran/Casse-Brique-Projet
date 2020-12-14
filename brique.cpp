#include "brique.h"


brique::brique(): element{}, d_longueur{4.0}, d_largeur{2.0} {}

brique::brique(double x, double y, double longueur, double largeur): element{x, y},
d_longueur{longueur}, d_largeur{largeur} {}

brique::~brique() = default;

void brique::collision(){

}


/*
brique::brique(double coordX, double coordY):d_x{coordX}, d_y{coordY}, d_longueur{longueurBrique}, d_largueur{largeurBrique}, d_color{YELLOW}
{

}

bool brique::detruite()
{
    if("brique est détruite")
        return true;
}

*/


/*
idée classe collision

template <class c1, class c2>
bool chevauchement(T1& a, T2& b)
{
    return (a.droite() >= b.gauche() && a.gauche() <= b.droite() &&
           a.bas() >= b.haut() && a.haut() <= b.bas());
}

void collision(raquette& rq, balle& ball)
{
    if(!chevauchement(rq, ball))
        return;

    ball.vélocité.y = -velocitéBalle;
    if(ball.x() < rq.x())
        ball.vélocité.x = -vélocitéBalle;
    else
        ball.vélocité.x = vélocitéBalle;
}

void collision(brique& bq, balle& ball)
{
    if(!chevauchement(bq, ball))
        return;
    bq.detruite() = true;

    double chevauchementGauche=ball.droite() - bq.gauche();
    double chevauchementDroite=bq.droite() - ball.gauche();
    double chevauchementHaut=ball.bas() - bq.haut();
    double chevauchementBas=bq.bas() - ball.haut();

    bool balleVenantGauche=abs(chevauchementGauche) < abs(chevauchementDroite);
    bool balleVenantHaut=abs(chevauchementHaut) < abs(chevauchementBas);

    double chevauchementX=balleVenantGauche ? chevauchementGauche : chevauchementDroite;
    double chevauchementY=balleVenantHaut ? chevauchementHaut : chevauchementBas;

    if(abs(chevauchementX) < abs(chevauchementY))
        ball.vélocité.x = balleVenantGauche ? -vélocitéBalle : vélocitéBalle;
    else
        ball.vélocité.y = balleVenantHaut ? -vélocitéBalle : vélocitéBalle;
}

*/
