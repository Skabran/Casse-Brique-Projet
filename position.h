#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include "vecteur.h"

class position
{
public:
    position(double x, double y);
    position(); // par default (0,0)
    double valeurX() const;
    double valeurY() const;
    void changePosition(double x, double y);
    void affiche(std::ostream& ost) const;
    void lit(std::istream& ist);
    bool operator==(const position& pos) const;
    position operator+(const vecteur& vect);


private:
    double d_x;
    double d_y;
};
std::ostream& operator<<(std::ostream& ost, const position& pos);
std::istream& operator>>(std::istream& ist, position& pos);
position operator+(const vecteur& vect, position& pos);

#endif // POSITION_H

