#ifndef ENVELOPPE_H
#define ENVELOPPE_H
#include "position.h"

/**
Class repr�sentent l'enveloppe rectangulaire d'un element et compos�e de 4 positions: HG, HD, BG, BD
*/
class enveloppe{
public:
///Constructeur de base de l'enveloppe
    enveloppe();
///Constructeur d'une enveloppe via 4 positions
    enveloppe(const position& coinHG, const position& coinHD, const position& coinBG, const position& coinBD);
///Destructeur de base de l'enveloppe
    ~enveloppe();


/**
Renvoie la position du coin en haut � gauche du rectangle
*/
    position getPointHG() const;


/**
Renvoie la position du coin en haut � droite du rectangle
*/
    position getPointHD() const;


/**
Renvoie la position du coin en bas � gauche du rectangle
*/
    position getPointBG() const;


/**
Renvoie la position du coin en bas � droite du rectangle
*/
    position getPointBD() const;


private:
/** Coin en haut � gauche du rectangle englobant */
    position d_pointHG;
/** Coin en haut � droite du rectangle englobant */
    position d_pointHD;
/** Coin en bas � gauche du rectangle englobant */
    position d_pointBG;
/** Coin en bas � droite du rectangle englobant */
    position d_pointBD;

};
#endif // ENVELOPPE_H
