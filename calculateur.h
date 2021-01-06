#ifndef CALCULATEUR_H
#define CALCULATEUR_H
#include "position.h"

/**
Classe permettant de faire les calcul séparement des element et des collisions
*/
class calculateur{
public:
///Constructeur par default du calculateur
    calculateur();
///Destructeur par default du calculateur
    ~calculateur();


/**
Calcul la position du coin en haut a gauche du rectangle a partir de sa position centrale
Si on donne une forme autre qu'un rectangle, il calcul le rectangle englobbant
    @param[in] pointCentral - Point central du rectangle
    @return la position du point en haut a gauche du rectangle
*/
    position pointHG(const position& pointCentral) const;


private:
};


#endif // CALCULATEUR_H
