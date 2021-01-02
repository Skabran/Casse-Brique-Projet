#ifndef RAQUETTE_H
#define RAQUETTE_H
#include "element.h"
#include "elementMouvant.h"

/**
Classe représentant la raquette : herite d'un elemant mouvant
*/
class raquette : public elementMouvant{
public:

/**
Constructeur de base de la raquette. Créer un element mouvant par default
et une raquette de longueur 4 et de largeur 2
*/
    raquette();

/**
Constructeur de la raquette. Créer un element mouvant de position (x,y) de longueur longueur et de largeur largeur
*/
    raquette(double x, double y, double longueur, double largeur);

///Destructeur par default de la raquette
    ~raquette();

/**
Déplace la raquette en fonction de l'utilisateur
q a gauche
d à droite
s remise au centre
*/
    void deplacer() override final;

/**
A FAIRE
*/
    bool testDeCollision(position posElementMouvant) override final;


/**
Applique l'effet d'une collision sur cet element
    @return d_positionElement - position de l'element
*/
    void effetCollision(element *elementPercute) override final;

private:
/** Valeur de la longueur de la raquette */
    double d_longueur;
/** Valeur de la largeur de la raquette */
    double d_largeur;

};

#endif // RAQUETTE_H
