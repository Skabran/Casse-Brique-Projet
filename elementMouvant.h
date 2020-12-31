#ifndef ELEMENTMOUVANT_H
#define ELEMENTMOUVANT_H
#include "element.h"
#include "vecteur.h"

/**
Classe des element mobile. Elle hérite des elements standards
*/
class elementMouvant : public element {
public:
///Constructeur par default position par default et vecteur vitesse par default
    elementMouvant();
///Constructeur a deux valeurs position(x,y) et vecteur vitesse par default
    elementMouvant(double x, double y);
///Constructeur a deux valeurs position(x,y) et vecteur vitesse(vitesse, angle)
    elementMouvant(double x, double y, double vitesse, double angle);
///Destructeur par default
    virtual ~elementMouvant();


/**
Renvoi le vecteur vitesse de l'element mouvant
*/
    vecteur getVecteur() const;


/**
Methode virtuelle. Permet aux elementMouvant de se déplacer en faisant varier leur position
*/
    virtual void deplacer() = 0;

/**
Methode virtuelle
A FAIRE
*/
    virtual bool collision(position posElementMouvant) override = 0;

private:
/** vecteur vitesse de l'element mouvant */
    vecteur d_vecteurVitesse;
};

#endif // ELEMENTMOUVANT_H
