#ifndef CALCULATEUR_H
#define CALCULATEUR_H
#include <cmath>
#include "enveloppe.h"
#include "brique.h"
#include "balle.h"
#include "raquette.h"

/**
Classe permettant de faire les calculs séparement des element et des collisions
*/
class calculateur{
public:
///Constructeur par default du calculateur
    calculateur();
///Destructeur par default du calculateur
    ~calculateur();

/**
Renvoie la position du coin en haut à gauche de l'enveloppe
    @param[in] positionCentre - position du centre de l'element
    @param[in] longueur - longueur de l'element
    @param[in] largeur - largeur de l'element
*/
    position calculPointHG(const position& positionCentre, const double longueur, const double largeur) const;


/**
Renvoie la position du coin en haut a droite de l'enveloppe
    @param[in] positionCentre - position du centre de l'element
    @param[in] longueur - longueur de l'element
    @param[in] largeur - largeur de l'element
*/
    position calculPointHD(const position& pos, const double longueur, const double largeur) const;


/**
Renvoie la position du coin en bas a gauche de l'enveloppe
    @param[in] positionCentre - position du centre de l'element
    @param[in] longueur - longueur de l'element
    @param[in] largeur - largeur de l'element
*/
    position calculPointBG(const position& pos, const double longueur, const double largeur) const;


/**
Renvoie la position du coin en bas a droite de l'enveloppe
    @param[in] positionCentre - position du centre de l'element
    @param[in] longueur - longueur de l'element
    @param[in] largeur - largeur de l'element
*/
    position calculPointBD(const position& pos, const double longueur, const double largeur) const;


/**
Calcul l'enveloppe d'une brique et la renvoie
    @return l'enveloppe de la brique
*/
    enveloppe calculEnveloppe(const brique& brique1) const;


/**
Calcul l'enveloppe d'une balle et la renvoie
    @return l'enveloppe de la balle
*/
    enveloppe calculEnveloppe(const balle& balle1) const;


/**
Calcul l'enveloppe d'une raquette et la renvoie
    @return l'enveloppe de la raquette
*/
    enveloppe calculEnveloppe(const raquette& raquette1) const;


/**
Calcul la distance entre deux positions
    @param[in] pos1 - position 1
    @param[in] pos2 - position 2
    @return la distance entre ces deux postions
*/
    double distance(const position& pos1, const position& pos2) const;


private:
};


#endif // CALCULATEUR_H
