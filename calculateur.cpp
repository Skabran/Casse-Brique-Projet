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


enveloppe calculateur::calculEnveloppe(const balle& balle1)
{
    double diametreBalle = balle1.getDiametre();
    position centreBalle{balle1.getPosition()};

    position coinHG = calculPointHG(centreBalle, diametreBalle , diametreBalle );
    position coinHD = calculPointHD(centreBalle, diametreBalle , diametreBalle );
    position coinBG = calculPointBG(centreBalle, diametreBalle , diametreBalle );
    position coinBD = calculPointBD(centreBalle, diametreBalle , diametreBalle );

    enveloppe env{coinHG, coinHD, coinBG, coinBD};
    return env;
}


enveloppe calculateur::calculEnveloppe(const raquette& raquette1)
{
    double longueurRaquette = raquette1.getLongueurRaquette();
    double largeurRaquette = raquette1.getLargeurRaquette();//
    position centreRaquette{raquette1.getPosition()};

    position coinHG = calculPointHG(centreRaquette, longueurRaquette , largeurRaquette );
    position coinHD = calculPointHD(centreRaquette, longueurRaquette , largeurRaquette );
    position coinBG = calculPointBG(centreRaquette, longueurRaquette , largeurRaquette );
    position coinBD = calculPointBD(centreRaquette, longueurRaquette , largeurRaquette );

    enveloppe env{coinHG, coinHD, coinBG, coinBD};
    return env;
}
