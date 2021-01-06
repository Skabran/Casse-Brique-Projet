#include "position.h"
#include <iostream>
#include <cmath>

position::position(): d_x{0.0}, d_y{0.0} {}

position::position(double x, double y): d_x{x}, d_y{y} {}

position::position(const position& pos) : d_x{pos.valeurX()}, d_y{pos.valeurY()} {}

position::~position() = default;

double position::valeurX() const
{
    return d_x;
}

double position::valeurY() const
{
    return d_y;
}

void position::affiche(std::ostream& ost) const
{
    ost<<"("<<d_x<<","<<d_y<<")";
}

void position::lit(std::istream& ist)
{
    char temp;
    ist>>temp>>d_x>>temp>>d_y>>temp;
}

void position::changePosition(double x, double y)
{
    d_x=x;
    d_y=y;
}

bool position::operator==(const position& pos) const
{
    if(d_x==pos.valeurX() && d_y==pos.valeurY())  //problème car égalité de double ?
    {
        return true;
    }
    return false;
}

position position::operator+(const vecteur& vect){
    d_x +=cos(vect.getAngle());
    d_y +=sin(vect.getAngle());
    return *this;
}

position& position::operator=(const position& pos)
{
    d_x=pos.valeurX();
    d_y=pos.valeurY();
}

std::ostream& operator<<(std::ostream& ost, const position& pos)
{
    pos.affiche(ost);
}

std::istream& operator>>(std::istream& ist, position& pos)
{
    pos.lit(ist);
}

position operator+(const vecteur& vect, position& pos){
    double nouveauX = pos.valeurX() + cos(vect.getAngle());
    double nouveauY = pos.valeurY() + sin(vect.getAngle());
    pos.changePosition(nouveauX,nouveauY);
    return pos;
}
