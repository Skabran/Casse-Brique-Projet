#ifndef ENVELOPPE_H
#define ENVELOPPE_H
#include "position.h"

/**
Class représentent l'enveloppe rectangulaire d'un element et composée de 4 positions: HG, HD, BG, BD
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
Renvoie la position du coin en haut à gauche du rectangle
*/
    position getPointHG() const;


/**
Renvoie la position du coin en haut à droite du rectangle
*/
    position getPointHD() const;


/**
Renvoie la position du coin en bas à gauche du rectangle
*/
    position getPointBG() const;


/**
Renvoie la position du coin en bas à droite du rectangle
*/
    position getPointBD() const;


private:
/** Coin en haut à gauche du rectangle englobant */
    position d_pointHG;
/** Coin en haut à droite du rectangle englobant */
    position d_pointHD;
/** Coin en bas à gauche du rectangle englobant */
    position d_pointBG;
/** Coin en bas à droite du rectangle englobant */
    position d_pointBD;

};
#endif // ENVELOPPE_H
