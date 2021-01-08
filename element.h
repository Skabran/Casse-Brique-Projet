#ifndef ELEMENT_H
#define ELEMENT_H
#include "position.h"

class affichageJeu;
class elementMouvant;

/**
Classe des element appartenant au jeu
*/
class element{
public:
///Constructeur par default de l'element avec une position par default
    element();
///Constructeur de l'element avec une position(x,y)
    element(double x, double y);
///Constructeur a partir d'une position
    element(position pos);
///Destructeur par default de l'element
    virtual ~element();

/**
Retourne la position de l'element
    @return d_positionElement - position de l'element
*/
    position getPosition() const;

/**
Change la position de l'element e la remplaçant par la position passé en parametre
    @param pos - Position que l'on souhaite donner a l'element
*/
    void changePosition(const position& pos);

/**
Methode virtuelle
Test si il y a collision entre cet element et la position passé en paramettre
*/
    virtual bool testDeCollision(position posElementMouvant) = 0;

/**
Methode virtuelle
Applique l'effet d'une collision d'un elementMouvant sur cet element
On passe l'elementMouvant en parametre pour plus tard si l'on veut créer des briques qui accélèrent la balle lorsqu'elle les touche
    @return d_positionElement - position de l'element
*/
    virtual void effetCollision(elementMouvant *elementPercute)=0;


/**
Methode virtuelle
Demande à l'afficheur d'afficher l'element
*/
    virtual void afficheElement(const affichageJeu& affichage) const =0 ;



private:
    /** position de l'element */
    position d_positionElement;
};

#endif // ELEMENT_H
