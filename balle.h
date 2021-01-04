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
    bool testDeCollision(position posElementMouvant) override final;


/**
Methode virtuelle
Applique l'effet d'une collision sur cet element
    @return d_positionElement - position de l'element
*/
    void effetCollision(element *elementPercute) override final;

/**
Déplace la balle en additionnant son vecteur vitesse à sa position et en mettant à jour sa position
*/
    void deplacer() override final;


/**
Demande à l'afficheur d'afficher l'element
*/
    void afficheElement() const override ;

private:
/**Taille du rayon de la balle*/
    double d_rayon;
};

#endif // BALLE_H
