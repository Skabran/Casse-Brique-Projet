#ifndef BRIQUE_H
#define BRIQUE_H
#include "element.h"

class affichageJeu;

/**
Classe de la brique de base du jeu. Herite de la classe element
*/
class brique : public element{
public:
///Constructeur par default de la brique. Element par default d_longueur = 40.0 et d_largeur = 20.0
    brique();
///Constructeur de la brique. Element(x, y), d_longueur = longueur et d_largeur = largeur
    brique(double x, double y, double longueur=40, double largeur=20);
///Destructeur de la brique par default
    ~brique();

/**
Renvoit la longueur de la brique
*/
    double getLongueurBrique() const;


/**
Renvoit la largeur de la brique
*/
    double getLargeurBrique() const;


/**
A FAIRE
*/
    bool testDeCollision(position posElementMouvant) override;

/**
Methode virtuelle
Applique l'effet d'une collision sur cet element
    @return d_positionElement - position de l'element
*/
    void effetCollision(element *elementPercute) override;


/**
Demande à l'afficheur d'afficher l'element
*/
    void afficheElement(const affichageJeu& affichage) const override;


private:
    /** longueur de la brique (taille selon l'axe x ) */
    double d_longueur;

    /** largeur de la brique (taille selon l'axe y ) */
    double d_largeur;
};

#endif // BRIQUE_H
