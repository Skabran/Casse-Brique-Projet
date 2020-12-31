#ifndef ELEMENT_H
#define ELEMENT_H
#include "position.h"

/**
Classe des element appartenant au jeu
*/
class element{
public:
///Constructeur par default de l'element avec une position par default
    element();
///Constructeur de l'element avec une position(x,y)
    element(double x, double y);
///Destructeur par default de l'element
    virtual ~element();

/**
Retourne la position de l'element
    @return d_positionElement - position de l'element
*/
    position getPosition() const;

/**
Methode virtuelle
A FAIRE
*/
    virtual bool collision(position posElementMouvant) = 0;


private:
    /** position de l'element */
    position d_positionElement;
};

#endif // ELEMENT_H
