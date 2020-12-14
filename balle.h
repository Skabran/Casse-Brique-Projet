#ifndef BALLE_H
#define BALLE_H
#include "elementMouvant.h"

class balle : public elementMouvant{
public:
    balle();
    balle(double x, double y);
    balle(double x, double y, double vitesse, double angle);
    ~balle();
    void collision() override final;
};

#endif // BALLE_H
/*
public :
    balle();
    balle(double coordX, coordY);
    void miseAJour();
    double x() const;
    double y() const;
    double gauche() const;
    double droite() const;
    double haut() const;
    double bas() const;
private:
    double d_x;
    double d_y;
    double d_rayon;
    double d_color;
*/
