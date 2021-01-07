#include "affichageJeu.h"

affichageJeu::affichageJeu(): d_longueurAffichage{} ,d_largeurAffichage {} {}

affichageJeu::~affichageJeu() {}

void affichageJeu::afficheVictoire() const
{

}

void affichageJeu::afficheDefaite() const
{

}


void affichageJeu::afficheEnveloppe(const enveloppe& env) const
{
    double coinHGX = env.getPointHG().valeurX();
    double coinHGY = env.getPointHG().valeurY();
    double coinBDX = env.getPointBD().valeurX();
    double coinBDY = env.getPointBD().valeurY();

    rectangle(coinHGX, coinHGY, coinBDX, coinBDY);
}


void affichageJeu::afficheBalle(const balle& balleAAfficher) const
{
    circle(balleAAfficher.getPosition().valeurX(), balleAAfficher.getPosition().valeurY(), (balleAAfficher.getDiametre())/2);
}

void affichageJeu::afficheBrique(const brique& briqueAAfficher) const
{
    enveloppe env;
    calculateur calc;
    env = calc.calculEnveloppe(briqueAAfficher);
    afficheEnveloppe(env);
}

void affichageJeu::afficheRaquette(const raquette& raquetteAAfficher) const
{
    enveloppe env;
    calculateur calc;
    env = calc.calculEnveloppe(raquetteAAfficher);
    afficheEnveloppe(env);
}
