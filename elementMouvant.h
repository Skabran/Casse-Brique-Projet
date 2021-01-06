#ifndef ELEMENTMOUVANT_H
#define ELEMENTMOUVANT_H
#include "element.h"
#include "vecteur.h"

class affichageJeu;

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
///Constructeur a partir d'une position et d'un vecteur
    elementMouvant(position pos, vecteur vect);
///Destructeur par default
    virtual ~elementMouvant();


/**
Renvoi le vecteur vitesse de l'element mouvant
*/
    vecteur getVecteur() const;


/**
Change la position de l'element e la remplaçant par la position passé en parametre
    @param pos - Position que l'on souhaite donner a l'element
*/
    void changeVecteur(const vecteur& vect);


/**
Methode virtuelle. Permet aux elementMouvant de se déplacer en faisant varier leur position
*/
    virtual void deplacer() = 0;

/**
Methode virtuelle
A FAIRE
*/
    virtual bool testDeCollision(position posElementMouvant) override = 0;


/**
Methode virtuelle
Applique l'effet d'une collision sur cet element
    @return d_positionElement - position de l'element
*/
    virtual void effetCollision(element *elementPercute) override=0;


/**
Methode virtuelle
Demande à l'afficheur d'afficher l'element
*/
    virtual void afficheElement(const affichageJeu& affichage) const override  =0;

private:
/** vecteur vitesse de l'element mouvant */
    vecteur d_vecteurVitesse;
};

#endif // ELEMENTMOUVANT_H
