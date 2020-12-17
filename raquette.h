#ifndef RAQUETTE_H
#define RAQUETTE_H
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
    bool collision() override final;

private:
/** Valeur de la longueur de la raquette */
    double d_longueur;
/** Valeur de la largeur de la raquette */
    double d_largeur;

};

/*
class rectangle
{
    public:
        rectangle(double coordX, coordY);
        double x() const;
        double y() const;
        double gauche() const;
        double droite() const;
        double haut() const;
        double bas() const;
    private:
        double d_x;
        double d_y;
        double d_longueur;
        double d_largueur;
        double d_color;

};

class raquette : public rectangle
{
    public :
        raquette();
        raquette(double coordX, double coordY);
        void miseAJour();
    private:
        "vélocité"
*/
#endif // RAQUETTE_H
