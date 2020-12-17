#ifndef BALLE_H
#define BALLE_H
#include "elementMouvant.h"

/**
Classe représentant la balle. Elle herite d'un elementMouvant
*/
class balle : public elementMouvant{
public:
///Constructeur par default balle (0,0) de rayon 1
    balle();

///Constructeur de balle de position (x,y) et de rayon "rayon"
    balle(double x, double y, double rayon);

///Constructeur de balle de position (x,y)  de rayon "rayon". Construit aussi son vecteur (vitesse, angle)
    balle(double x, double y, double vitesse, double angle, double rayon);

///Destructeur par default de balle
    ~balle();

/** A FAIRE */
    bool collision() override final;

/**
Déplace la balle en additionnant son vecteur vitesse a sa position et en mettant a jour sa position
*/
    void deplacer() override final;

private:
/**Taille du rayon de la balle*/
    double d_rayon;
};

#endif // BALLE_H
/*
public :
    balle();
    balle(double coordX, coordY);
    void miseAJour();
    double x() const;
    double y() const;
    double gauche() const;
    double droite() const;
    double haut() const;
    double bas() const;
private:
    double d_x;
    double d_y;
    double d_rayon;
    double d_color;
*/
