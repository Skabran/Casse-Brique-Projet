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
///Construvteur a partir d'une position
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

//A PASSER en global comme effetCollision ??? (sans doute)
/**
Methode virtuelle
Test si il y a collision entre cet element et la position passé en paramettre
*/
    virtual bool testDeCollision(position posElementMouvant) = 0;

/**
Methode virtuelle
Applique l'effet d'une collision sur cet element
    @return d_positionElement - position de l'element
*/
    virtual void effetCollision(element *elementPercute)=0;



private:
    /** position de l'element */
    position d_positionElement;
};

#endif // ELEMENT_H
