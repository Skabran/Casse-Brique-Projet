#ifndef BALLE_H
#define BALLE_H
#include "elementMouvant.h"

class affichageJeu;

/**
Classe représentant la balle. Elle herite d'un elementMouvant
*/
class balle : public elementMouvant{
public:
///Constructeur par default balle (0,0) de diametre 30
    balle();

///Constructeur de balle de position (x,y) et de diametre "diametre"
    balle(double x, double y, double diametre=30);

///Constructeur de balle a partir d'une position(x,y) d'une vitesse d'un angle et d'un diametre
    balle(const position& pos, double vitesse, double angle, double diametre=30);

///Constructeur de balle de position (x,y)  de diametre "diametre". Construit aussi son vecteur (vitesse, angle)
    balle(double x, double y, double vitesse, double angle, double diametre=30);

///Destructeur par default de balle
    ~balle();

/** A FAIRE */
    bool testDeCollision(position posElementMouvant) override final;


/**
Renvoi le diametre de la balle
*/
    double getDiametre() const;



/**
Applique l'effet d'une collision d'un elementMouvant sur cet element
    @return d_positionElement - position de l'element
*/
    void effetCollision(elementMouvant *elementPercute) override final;


/**
Applique l'effet d'une collision sur un element
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
    void afficheElement(const affichageJeu& affichage) const override ;

private:
/**Taille du diametre de la balle*/
    double d_diametre;
};

#endif // BALLE_H
