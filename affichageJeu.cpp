#include "affichageJeu.h"

affichageJeu::affichageJeu() {}

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
    setcolor(RED);
    double x=balleAAfficher.getPosition().valeurX();
    double y=balleAAfficher.getPosition().valeurY();
    setfillstyle(HATCH_FILL, RED);
    circle(x, y, (balleAAfficher.getDiametre())/2);
    floodfill(x,y,RED);
}

void affichageJeu::afficheBrique(const brique& briqueAAfficher) const
{
    setcolor(GREEN);
    enveloppe env;
    calculateur calc;
    setfillstyle(LTSLASH_FILL, GREEN);
    env = calc.calculEnveloppe(briqueAAfficher);
    afficheEnveloppe(env);
    floodfill(briqueAAfficher.getPosition().valeurX(),briqueAAfficher.getPosition().valeurY(),GREEN);
}

void affichageJeu::afficheRaquette(const raquette& raquetteAAfficher) const
{
    setcolor(YELLOW);
    enveloppe env;
    calculateur calc;
    setfillstyle(LTSLASH_FILL, YELLOW);
    env = calc.calculEnveloppe(raquetteAAfficher);
    afficheEnveloppe(env);
    floodfill(raquetteAAfficher.getPosition().valeurX(),raquetteAAfficher.getPosition().valeurY(),YELLOW);
}


void affichageJeu::afficheTerrain(const terrain& terrainAAfficher) const
{
    double longueur = terrainAAfficher.getLongueurTerrain();
    double largeur = terrainAAfficher.getLargeurTerrain();
    opengraphsize(longueur+10,largeur); //+10 car la fenetre s'ouvre un petit peut trop a gauche pour une raison que j'ignore
    setcolor(RED);
    line(0,0,longueur,0);
    line(0,0,0,largeur);
    line(longueur,0,longueur,largeur);
    std::vector<element*> elements = terrainAAfficher.getElement();
    for(unsigned int i=0; i<elements.size(); i++)
    {
        elements[i]->afficheElement(*this);
    }
    getch();
    closegraph();
}
