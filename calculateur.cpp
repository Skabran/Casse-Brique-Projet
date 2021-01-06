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

}
