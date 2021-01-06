#include "calculateur.h"

calculateur::calculateur() {}

calculateur::~calculateur() {}

position calculateur::calculPointHG(const position& positionCentre, const double longueur, const double largeur)
{
    position pos;
    double nouveauX;
    double nouveauY;
    nouveauX = positionCentre.valeurX()-(longueur/2);
    nouveauY = positionCentre.valeurY()+(largeur/2);
    pos.changePosition(nouveauX, nouveauY);
    return pos;
}


position calculateur::calculPointHD(const position& positionCentre, const double longueur, const double largeur)
{
    position pos;
    double nouveauX;
    double nouveauY;
    nouveauX = positionCentre.valeurX()+(longueur/2);
    nouveauY = positionCentre.valeurY()+(largeur/2);
    pos.changePosition(nouveauX, nouveauY);
    return pos;
}

position calculateur::calculPointBG(const position& positionCentre, const double longueur, const double largeur)
{
    position pos;
    double nouveauX;
    double nouveauY;
    nouveauX = positionCentre.valeurX()-(longueur/2);
    nouveauY = positionCentre.valeurY()-(largeur/2);
    pos.changePosition(nouveauX, nouveauY);
    return pos;
}


position calculateur::calculPointBD(const position& positionCentre, const double longueur, const double largeur)
{
    position pos;
    double nouveauX;
    double nouveauY;
    nouveauX = positionCentre.valeurX()+(longueur/2);
    nouveauY = positionCentre.valeurY()-(largeur/2);
    pos.changePosition(nouveauX, nouveauY);
    return pos;
}


enveloppe calculateur::calculEnveloppe(const brique& brique1)
{
    double longueurBrique = brique1.getLongueurBrique();
    double largeurBrique = brique1.getLargeurBrique();
    position centreBrique{brique1.getPosition()};

    position coinHG = calculPointHG(centreBrique, longueurBrique , largeurBrique );
    position coinHD = calculPointHD(centreBrique, longueurBrique , largeurBrique );
    position coinBG = calculPointBG(centreBrique, longueurBrique , largeurBrique );
    position coinBD = calculPointBD(centreBrique, longueurBrique , largeurBrique );

    enveloppe env{coinHG, coinHD, coinBG, coinBD};
    return env;
}
