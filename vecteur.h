#ifndef VECTEUR_H
#define VECTEUR_H


class vecteur{
public :
    vecteur();
    ~vecteur();
    double getVitesse() const;
    double getAngle() const;
    void multiplieVitesse(double coef);
    void inverseHorizontale();
    void inverseVertical();
    vecteur operator*(double coef);

private :
    double d_vitesse;
    double d_angle;

};

vecteur operator*(double coef,vecteur& vect);

#endif // VECTEUR_H
