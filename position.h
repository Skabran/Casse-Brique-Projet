#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include "vecteur.h"

/**
Classe repr�sentant une position a deux coordonn�es
*/
class position
{
public:
///Constructeur par default position (0,0)
    position();
///Constructeur a deux valeurs position (x,y)
    position(double x, double y);
///Destructeur par default
    ~position();
/**
Retourne la position de x
    @return d_x - valeur de x
*/
    double valeurX() const;

/**
Retourne la position de y
    @return d_y - valeur de y
*/
    double valeurY() const;

/**
Affiche un point
    @param[in] ost - flot de lecture
*/
    void affiche(std::ostream& ost) const;

/**
Lit un point
    @param[in] ist - flot d'ecriture
*/
    void lit(std::istream& ist);

/**
Change la position d'un point
    @param[in] x - valeur de x
    @param[in] y - valeur de y
*/
    void changePosition(double x, double y);

/**
Operateur == : test si deux point on la m�me position
    @param[in] pos - point a tester
    @return vrai si les position x et y des deux point sont �gales, faux sinon
*/
    bool operator==(const position& pos) const;

/**
Operateur + : additionne un point et un vecteur
    @param[in] vect - vecteur a additionner au point
    @return Le point avec ses nouvelles coordonn�es
*/
    position operator+(const vecteur& vect);

/**
Operateur = : remplace les x et y de la premi�re position par ceux de la seconde
    @param[in] pos - position a copier
    @return la position dont les parametres sont chang�s
*/
    position& operator=(const position& pos);

private:
    /** Coordonn�es x */
    double d_x;
    /** Coordonn�e y */
    double d_y;
};

/**
Operateur << : ecrit un point sur un flot sortant
    @param[in] ost - flot sortant
    @param[in] pos - point � ecrire
*/
std::ostream& operator<<(std::ostream& ost, const position& pos);

/**
Operateur >> : lit un point sur un flot entrant
    @param[in] ist - flot entrant
    @param[in] pos - point � lire
*/
std::istream& operator>>(std::istream& ist, position& pos);

/**
Operateur + : additionne un vecteur et un point
    @param[in] vecteur - vecteur � additionner
    @param[in] pos - point � additionner
*/
position operator+(const vecteur& vect, position& pos);

#endif // POSITION_H

