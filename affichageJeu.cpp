#include "affichageJeu.h"

affichageJeu::affichageJeu(): d_longueurAffichage{} ,d_largeurAffichage {} {}

affichageJeu::~affichageJeu() {}

void affichageJeu::afficheVictoire() const
{

}

void affichageJeu::afficheDefaite() const
{

}


void affichageJeu::afficheBalle(const balle& balleAAfficher) const
{
    circle(balleAAfficher.getPosition().valeurX(), balleAAfficher.getPosition().valeurY(), (balleAAfficher.getDiametre())/2);
}

void affichageJeu::afficheBrique(const brique& briqueAAfficher) const
{

}
