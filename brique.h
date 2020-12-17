#ifndef BRIQUE_H
#define BRIQUE_H
#include "element.h"

class brique : public element{
public:
    brique();
    brique(double x, double y, double longueur, double largeur);
    ~brique();
    bool collision() override;
private:
    double d_longueur;
    double d_largeur;
};

#endif // BRIQUE_H

/*
class brique : public rectangle
{
    public:
        bool detruite() = false;
        brique(double coordX, double coordY);
};
*/
