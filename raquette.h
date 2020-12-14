#ifndef RAQUETTE_H
#define RAQUETTE_H
#include "elementMouvant.h"

class raquette : public elementMouvant{
public:
    raquette();
    raquette(double x, double y, double longueur, double largeur);
    ~raquette();
    void deplacer() override final;
    void collision() override final;

private:
    double d_longueur;
    double d_largeur;

};

/*
class rectangle
{
    public:
        rectangle(double coordX, coordY);
        double x() const;
        double y() const;
        double gauche() const;
        double droite() const;
        double haut() const;
        double bas() const;
    private:
        double d_x;
        double d_y;
        double d_longueur;
        double d_largueur;
        double d_color;

};

class raquette : public rectangle
{
    public :
        raquette();
        raquette(double coordX, double coordY);
        void miseAJour();
    private:
        "v�locit�"
*/
#endif // RAQUETTE_H
